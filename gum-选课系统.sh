#!/bin/bash

#wget https://github.com/charmbracelet/gum/releases/download/v0.16.1/gum_0.16.1_Linux_x86_64.tar.gz
# tar -xzf gum_Linux_x86_64.tar.gz
# sudo mv gum /usr/local/bin/
BASE_DIR="/opt/student"
COURSE_FILE="$BASE_DIR/courses.txt"
LOG_FILE="$BASE_DIR/system.log"

mkdir -p "$BASE_DIR"
touch "$COURSE_FILE" "$LOG_FILE"
# 初始化文件
init_files() {
  if [ ! -s "$COURSE_FILE" ]; then
    cat > "$COURSE_FILE" <<EOF
C001|高等数学|0|30
C002|大学英语|0|30
C003|计算机基础|0|30
EOF
  fi

  if [ ! -s "$BASE_DIR/students.txt" ]; then
    cat > "$BASE_DIR/students.txt" <<EOF
2025001|张三|stu1
2025002|李四|stu2
2025003|王五|stu3
EOF
  fi
}
init_files

declare -A STUDENT_INFO=(
  ["stu1"]="2025001|张三"
  ["stu2"]="2025002|李四"
  ["stu3"]="2025003|王五"
)

log_action() {
  local user=$1 action=$2
  echo "$(date '+%F %T') [$user] $action" >> "$LOG_FILE"
}

login() {
  local role=$1
  while true; do
    user=$(gum input --placeholder "请输入用户名" --header "💻 用户登录" --prompt "用户名:")
    [ -z "$user" ] && return 1
    passwd=$(gum input --password --placeholder "请输入密码" --prompt "密码:")
    [ -z "$passwd" ] && return 1

    # 显示动态旋转动画，最长等待3秒
    gum spin --spinner moon --title "身份验证中，请稍候..." --timeout 3 & spinner_pid=$!

    # 模拟验证延时（你可以改成实际验证代码）
    sleep 2

    # 结束旋转动画
    kill $spinner_pid 2>/dev/null
    wait $spinner_pid 2>/dev/null

    if [[ "$role" == "student" ]]; then
      if [[ ${STUDENT_INFO[$user]+_} ]]; then
        if [[ "$passwd" == "gk12345678" ]]; then
          log_action "$user" "学生登录成功"
          gum style --foreground=green --bold "🎉 登录成功，欢迎学生 $user！"
          student_menu "$user"
          return 0
        else
          gum style --foreground=red "❌ 密码错误！请重试。"
          log_action "$user" "学生密码错误"
        fi
      else
        gum style --foreground=red "❌ 学生用户名不存在！"
        log_action "$user" "学生用户名不存在"
      fi
    else
      if [[ "$user" == "tea1" || "$user" == "tea2" ]]; then
        if [[ "$passwd" == "gk12345678" ]]; then
          log_action "$user" "教师登录成功"
          gum style --foreground=green --bold "🎉 登录成功，欢迎教师 $user！"
          teacher_menu "$user"
          return 0
        else
          gum style --foreground=red "❌ 密码错误！请重试。"
          log_action "$user" "教师密码错误"
        fi
      else
        gum style --foreground=red "❌ 教师用户名不存在！"
        log_action "$user" "教师用户名不存在"
      fi
    fi
  done
}

login_menu() {
  while true; do
    choice=$(gum choose --header "请选择登录身份" "学生身份登录系统" "教师身份登录系统" "退出系统")
    case $choice in
      "学生身份登录系统") login "student" ;;
      "教师身份登录系统") login "teacher" ;;
      "退出系统") 
        gum style --foreground=cyan "感谢使用，再见！👋"
        exit 0 ;;
    esac
  done
}


login_menu() {
  while true; do
    choice=$(gum choose "学生身份登录系统" "教师身份登录系统" "退出系统")
    case $choice in
      "学生身份登录系统") login "student" ;;
      "教师身份登录系统") login "teacher" ;;
      "退出系统") exit 0 ;;
    esac
  done
}

student_menu() {
  local user=$1
  while true; do
    choice=$(gum choose "学生选择课程" "学生查看信息" "退出登录")
    case $choice in
      "学生选择课程") student_select_course "$user" ;;
      "学生查看信息") student_view_info "$user" ;;
      "退出登录") break ;;
    esac
  done
}

teacher_menu() {
  local user=$1
  while true; do
    choice=$(gum choose "添加课程" "删除课程" "查看课程" "修改课程信息" "查看选课学生名单" "导出课程选课数据 (CSV)" "查看课程选课统计" "退出登录")
    case $choice in
      "添加课程") teacher_add_course "$user" ;;
      "删除课程") teacher_delete_course "$user" ;;
      "查看课程") teacher_view_course "$user" ;;
      "修改课程信息") teacher_modify_course "$user" ;;
      "查看选课学生名单") teacher_view_course_students "$user" ;;
      "导出课程选课数据 (CSV)") teacher_export_course_data "$user" ;;
      "查看课程选课统计") teacher_course_statistics "$user" ;;
      "退出登录") break ;;
    esac
  done
}

student_select_course() {
  local user=$1
  local selected_file="$BASE_DIR/selected_courses_${user}.txt"
  touch "$selected_file"

  declare -A selected_map=()
  while IFS= read -r cid; do
    [ -n "$cid" ] && selected_map["$cid"]=1
  done < "$selected_file"

  # 显示已选课程
  if [ ${#selected_map[@]} -gt 0 ]; then
    gum style --bold "您当前已选课程："
    for cid in "${!selected_map[@]}"; do
      cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d'|' -f2)
      echo "- $cid - $cname"
    done | gum format
  else
    gum style "您尚未选课。"
  fi

  # 是否替换已选课程
  if gum confirm "是否想要替换已选课程？"; then
    # 取消课程选择
    cancel_choices=()
    for cid in "${!selected_map[@]}"; do
      cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d'|' -f2)
      cancel_choices+=("$cid" "$cname")
    done
    if [ ${#cancel_choices[@]} -eq 0 ]; then
      gum style "无可取消课程。"
    else
      cancel_selected=$(gum choose --limit 0 "${cancel_choices[@]}")
      for cid in $cancel_selected; do
        sed -i "/^${cid}$/d" "$selected_file"
        unset selected_map["$cid"]

        line=$(grep "^${cid}|" "$COURSE_FILE")
        cname=$(echo "$line" | cut -d'|' -f2)
        cnum=$(echo "$line" | cut -d'|' -f3)
        maxnum=$(echo "$line" | cut -d'|' -f4)
        sed -i "s/^${cid}|${cname}|${cnum}|${maxnum}/${cid}|${cname}|$((cnum - 1))|${maxnum}/" "$COURSE_FILE"
      done
      gum style "取消课程成功。"
    fi
  fi

  # 选择新课程
  max_courses=3
  remaining=$((max_courses - ${#selected_map[@]}))
  if ((remaining <= 0)); then
    gum style --foreground=red "已达到最大选课数($max_courses门)。"
    return
  fi

  available_courses=()
  while IFS='|' read -r cid cname cnum maxnum; do
    [[ ${selected_map[$cid]} ]] && continue
    ((cnum >= maxnum)) && continue
    remain=$((maxnum - cnum))
    available_courses+=("$cid" "$cname (剩余:$remain)")
  done < "$COURSE_FILE"

  if [ ${#available_courses[@]} -eq 0 ]; then
    gum style "无可选课程。"
    return
  fi

  choices=$(gum choose --limit $remaining "${available_courses[@]}")

  added=""
  for cid in $choices; do
    echo "$cid" >> "$selected_file"
    selected_map["$cid"]=1
    line=$(grep "^${cid}|" "$COURSE_FILE")
    cname=$(echo "$line" | cut -d'|' -f2)
    cnum=$(echo "$line" | cut -d'|' -f3)
    maxnum=$(echo "$line" | cut -d'|' -f4)
    sed -i "s/^${cid}|${cname}|${cnum}|${maxnum}/${cid}|${cname}|$((cnum + 1))|${maxnum}/" "$COURSE_FILE"
    added+="$cid - $cname\n"
  done

  gum style --bold "选课成功，已添加课程："
  echo -e "$added" | gum format
}

student_view_info() {
  local user=$1
  local selected_file="$BASE_DIR/selected_courses_${user}.txt"

  info_line=$(grep "|${user}$" "$BASE_DIR/students.txt")
  if [ -z "$info_line" ]; then
    gum style --foreground=red "未找到用户信息，请联系管理员。"
    return
  fi

  sno=$(echo "$info_line" | cut -d'|' -f1)
  name=$(echo "$info_line" | cut -d'|' -f2)

  gum style --bold "学生信息："
  echo "学号: $sno"
  echo "姓名: $name"

  if [ ! -f "$selected_file" ] || [ ! -s "$selected_file" ]; then
    gum style "尚未选课。"
  else
    gum style "已选课程："
    while read -r cid; do
      cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d'|' -f2)
      echo "$cid - $cname"
    done < "$selected_file" | gum format
  fi
}

teacher_add_course() {
  local user=$1
  cid=$(gum input --placeholder "请输入课程编号（例如 C004）")
  cname=$(gum input --placeholder "请输入课程名称")
  maxnum=$(gum input --placeholder "请输入课程最大容量" --value "30")

  if grep -q "^$cid|" "$COURSE_FILE"; then
    gum style --foreground=red "课程编号已存在！"
    return
  fi

  echo "$cid|$cname|0|$maxnum" >> "$COURSE_FILE"
  log_action "$user" "添加课程 $cid $cname"
  gum style "课程添加成功。"
}

teacher_delete_course() {
  local user=$1
  lines=()
  while IFS='|' read -r cid cname cnum maxnum; do
    lines+=("$cid" "$cname")
  done < "$COURSE_FILE"

  choice=$(gum choose "${lines[@]}")
  if [ -z "$choice" ]; then
    gum style "取消操作。"
    return
  fi

  # 删除课程
  sed -i "/^$choice|/d" "$COURSE_FILE"
  # 删除所有学生选课中该课程
  for file in "$BASE_DIR"/selected_courses_*.txt; do
    sed -i "/^$choice$/d" "$file"
  done

  log_action "$user" "删除课程 $choice"
  gum style "课程删除成功。"
}

teacher_view_course() {
  gum style --bold "当前课程列表："
  column -t -s '|' "$COURSE_FILE" | gum format
}

# 入口
login_menu

#!/bin/bash
dir="./con.txt"

if [ ! -f $dir  ]; then
  touch $dir
fi

read -p "输入你的姓名" name
read -p "输入你的电话号码" phone

echo $name >> con.txt
echo $phone >> con.txt

echo "你的信息已经保存在con.txt文件当中"
cat con.txt
