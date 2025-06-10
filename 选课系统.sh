#!/bin/bash

#!/bin/bash

BASE_DIR="/opt/student"
COURSE_FILE="$BASE_DIR/courses.txt"
LOG_FILE="$BASE_DIR/system.log"

# 创建目录（如果不存在）
if [ ! -d "$BASE_DIR" ]; then
  mkdir -p "$BASE_DIR"
fi

# 创建课程文件（如果不存在）
if [ ! -f "$COURSE_FILE" ]; then
  touch "$COURSE_FILE"
  # 可选：添加表头或初始数据
  # echo "CID|课程名|已选人数|最大人数" >> "$COURSE_FILE"
fi

# 创建日志文件（如果不存在）
if [ ! -f "$LOG_FILE" ]; then
  touch "$LOG_FILE"
fi
录记录日志

USER_GROUP_STUDENT="student"
USER_GROUP_TEACHER="teacher"


init_students_file() {
  if [ ! -f "$BASE_DIR/students.txt" ]; then
    echo -e "2025001|张三|stu1\n2025002|李四|stu2\n2025003|王五|stu3" > "$BASE_DIR/students.txt"
  fi
}

declare -A STUDENT_INFO=(
  ["stu1"]="2025001|张三"
  ["stu2"]="2025002|李四"
  ["stu3"]="2025003|王五"
)

# 日志记录函数
log_action() {
  local user=$1
  local action=$2
  echo "$(date '+%F %T') [$user] $action" >> "$LOG_FILE"
}

# 初始化课程文件
init_courses() {
  mkdir -p "$BASE_DIR"
  if [ ! -f "$COURSE_FILE" ]; then
    echo -e "C001|高等数学|0|30\nC002|大学英语|0|30\nC003|计算机基础|0|30" > "$COURSE_FILE"
  fi
}

# 登录菜单
login_menu() {
  while true; do
    CHOICE=$(dialog --clear --backtitle "学生选课系统" --title "登录" \
      --menu "请选择身份登录：" 10 50 3 \
      1 "学生身份登录系统" \
      2 "教师身份登录系统" \
      3 "退出系统" 3>&1 1>&2 2>&3)

    case $CHOICE in
      1) login "student" ;;
      2) login "teacher" ;;
      3) clear; exit 0 ;;
      *) ;;
    esac
  done
}

# 登录
login() {
  local role=$1
  local user passwd

  while true; do
    user=$(dialog --clear --inputbox "请输入用户名：" 8 40 3>&1 1>&2 2>&3)
    [ -z "$user" ] && return
    passwd=$(dialog --clear --insecure --passwordbox "请输入密码：" 8 40 3>&1 1>&2 2>&3)
    [ -z "$passwd" ] && return

    if [[ "$role" == "student" ]]; then
      if [[ ${STUDENT_INFO[$user]+_} ]]; then
        if [ "$passwd" == "gk12345678" ]; then
          log_action "$user" "学生登录成功"
          student_menu "$user"
          return
        else
          dialog --msgbox "密码错误！" 6 30
          log_action "$user" "学生密码错误"
        fi
      else
        dialog --msgbox "学生用户名不存在！" 6 30
        log_action "$user" "学生用户名不存在"
      fi
    else
      if [[ "$user" == "tea1" || "$user" == "tea2" ]]; then
        if [ "$passwd" == "gk12345678" ]; then
          log_action "$user" "教师登录成功"
          teacher_menu "$user"
          return
        else
          dialog --msgbox "密码错误！" 6 30
          log_action "$user" "教师密码错误"
        fi
      else
        dialog --msgbox "教师用户名不存在！" 6 30
        log_action "$user" "教师用户名不存在"
      fi
    fi
  done
}

# 学生菜单
student_menu() {
  local user=$1
  while true; do
    CHOICE=$(dialog --clear --backtitle "学生选课系统（学生）" --title "学生菜单" \
      --menu "欢迎 $user，请选择操作：" 10 50 3 \
      1 "学生选择课程" \
      2 "学生查看信息" \
      3 "退出系统" 3>&1 1>&2 2>&3)

    case $CHOICE in
      1) student_select_course "$user" ;;
      2) student_view_info "$user" ;;
      3) break ;;
      *) ;;
    esac
  done
}

# 教师菜单
teacher_menu() {
  local user=$1
  while true; do
    CHOICE=$(dialog --clear --backtitle "学生选课系统（教师）" --title "教师菜单" \
      --menu "欢迎 $user，请选择操作：" 20 60 10 \
      1 "添加课程" \
      2 "删除课程" \
      3 "查看课程" \
      4 "修改课程信息" \
      5 "查看选课学生名单" \
      6 "导出课程选课数据 (CSV)" \
      7 "查看课程选课统计" \
      8 "退出系统" 3>&1 1>&2 2>&3)

    case $CHOICE in
      1) teacher_add_course "$user" ;;
      2) teacher_delete_course "$user" ;;
      3) teacher_view_course "$user" ;;
      4) teacher_modify_course "$user" ;;
      5) teacher_view_course_students "$user" ;;
      6) teacher_export_course_data "$user" ;;
      7) teacher_course_statistics "$user" ;;
      8) break ;;
    esac
  done
}

#修改课程信息
teacher_modify_course() {
  local user=$1
  local courses=()

  while IFS="|" read -r cid cname cnum maxnum; do
    courses+=("$cid" "$cname")
  done < "$COURSE_FILE"

  if [ ${#courses[@]} -eq 0 ]; then
    dialog --msgbox "暂无课程可供修改。" 6 40
    return
  fi

  local cid
  cid=$(dialog --clear --menu "请选择要修改的课程：" 20 60 10 "${courses[@]}" 3>&1 1>&2 2>&3) || return

  local old_line=$(grep "^${cid}|" "$COURSE_FILE")
  local cname=$(echo "$old_line" | cut -d"|" -f2)
  local cnum=$(echo "$old_line" | cut -d"|" -f3)
  local maxnum=$(echo "$old_line" | cut -d"|" -f4)

  local new_cname=$(dialog --inputbox "请输入新的课程名称：" 8 40 "$cname" 3>&1 1>&2 2>&3) || return
  local new_maxnum=$(dialog --inputbox "请输入新的最大人数：" 8 40 "$maxnum" 3>&1 1>&2 2>&3) || return

  sed -i "s/^${cid}|${cname}|${cnum}|${maxnum}/${cid}|${new_cname}|${cnum}|${new_maxnum}/" "$COURSE_FILE"

  dialog --msgbox "课程信息修改成功！" 6 30
}


# 查看选课学生名单
teacher_view_course_students() {
  local user=$1
  local courses=()

  while IFS="|" read -r cid cname cnum maxnum; do
    courses+=("$cid" "$cname")
  done < "$COURSE_FILE"

  if [ ${#courses[@]} -eq 0 ]; then
    dialog --msgbox "暂无课程。" 6 40
    return
  fi

  local cid
  cid=$(dialog --menu "请选择要查看学生名单的课程：" 20 60 10 "${courses[@]}" 3>&1 1>&2 2>&3) || return

  local student_list=""
  for file in "$BASE_DIR"/selected_courses_*.txt; do
    grep -q "^$cid$" "$file" || continue
    local uid=$(basename "$file" | sed 's/selected_courses_\(.*\)\.txt/\1/')
    local info=$(grep "|$uid$" "$BASE_DIR/students.txt")
    local sno=$(echo "$info" | cut -d"|" -f1)
    local name=$(echo "$info" | cut -d"|" -f2)
    student_list+="$sno - $name\n"
  done

  dialog --msgbox "课程 [$cid] 的学生名单：\n\n${student_list:-无学生选课}" 20 60
}


# 导出课程选课数据 (CSV)
teacher_export_course_data() {
  local user=$1
  local courses=()

  while IFS="|" read -r cid cname cnum maxnum; do
    courses+=("$cid" "$cname")
  done < "$COURSE_FILE"

  if [ ${#courses[@]} -eq 0 ]; then
    dialog --msgbox "暂无课程可导出数据。" 6 40
    return
  fi

  local cid
  cid=$(dialog --menu "请选择要导出选课数据的课程：" 20 60 10 "${courses[@]}" 3>&1 1>&2 2>&3) || return

  local export_file="${BASE_DIR}/course_${cid}_students.csv"
  echo "学号,姓名" > "$export_file"

  for file in "$BASE_DIR"/selected_courses_*.txt; do
    grep -q "^$cid$" "$file" || continue
    local uid=$(basename "$file" | sed 's/selected_courses_\(.*\)\.txt/\1/')
    local info=$(grep "|$uid$" "$BASE_DIR/students.txt")
    local sno=$(echo "$info" | cut -d"|" -f1)
    local name=$(echo "$info" | cut -d"|" -f2)
    echo "$sno,$name" >> "$export_file"
  done

  dialog --msgbox "已导出课程 $cid 的选课学生名单到文件：\n$export_file" 10 60
}

#查看课程选课统计
teacher_course_statistics() {
  local total=0
  local full=0
  local display=""
  while IFS="|" read -r cid cname cnum maxnum; do
    total=$((total + 1))
    [ "$cnum" -eq "$maxnum" ] && full=$((full + 1))
    display+="$cid - $cname ： $cnum/$maxnum\n"
  done < "$COURSE_FILE"

  dialog --msgbox "当前总课程数：$total\n已满课程数：$full\n\n各课程选课情况：\n$display" 20 60
}

# 学生选课
student_select_course() {
  local user=$1
  local selected_file="$BASE_DIR/selected_courses_${user}.txt"
  local max_courses=3

  [ ! -f "$selected_file" ] && touch "$selected_file"

  declare -A selected_map
  while read -r cid; do
    [[ -n "$cid" ]] && selected_map["$cid"]=1
  done < "$selected_file"

  local selected_list=""
  for cid in "${!selected_map[@]}"; do
    local cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d"|" -f2)
    selected_list+="$cid - $cname\n"
  done

  dialog --title "📚 已选课程" --msgbox "$( [ -n "$selected_list" ] && echo -e "您当前已选课程（${#selected_map[@]} 门）:\n$selected_list" || echo "您尚未选课。" )" 12 60

  dialog --yesno "是否想要替换已选课程？" 7 40
  if [ $? -eq 0 ]; then
    # 选择需要取消的课程
    local cancel_choices=()
    for cid in "${!selected_map[@]}"; do
      local cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d"|" -f2)
      cancel_choices+=("$cid" "$cname" off)
    done

    local cancel
    cancel=$(dialog --checklist "请选择要取消的课程：" 15 60 8 "${cancel_choices[@]}" 3>&1 1>&2 2>&3)

    # 执行取消
    for cid in $cancel; do
      sed -i "/^${cid}$/d" "$selected_file"
      unset selected_map["$cid"]

      local cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d"|" -f2)
      local line=$(grep "^${cid}|" "$COURSE_FILE")
      local cnum=$(echo "$line" | cut -d"|" -f3)
      local maxnum=$(echo "$line" | cut -d"|" -f4)
      sed -i "s/^${cid}|${cname}|${cnum}|${maxnum}/${cid}|${cname}|$((cnum - 1))|${maxnum}/" "$COURSE_FILE"
    done
  fi

  # 构建候选课程
  local available_courses=()
  while IFS="|" read -r cid cname cnum maxnum; do
    [[ -n "${selected_map[$cid]}" ]] && continue
    [[ $cnum -ge $maxnum ]] && continue
    local remain=$((maxnum - cnum))
    available_courses+=("$cid" "$cname (剩余:$remain)" off)
  done < "$COURSE_FILE"

  local remaining=$((max_courses - ${#selected_map[@]}))
  if [ $remaining -le 0 ]; then
    dialog --msgbox "您已达到最大选课数（$max_courses 门）" 6 40
    return
  fi

  local choices
  choices=$(dialog --checklist "请选择新课程（最多选 $remaining 门）：" 20 70 10 "${available_courses[@]}" 3>&1 1>&2 2>&3)

  local added=""
  for cid in $choices; do
    echo "$cid" >> "$selected_file"
    selected_map["$cid"]=1

    local cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d"|" -f2)
    local line=$(grep "^${cid}|" "$COURSE_FILE")
    local cnum=$(echo "$line" | cut -d"|" -f3)
    local maxnum=$(echo "$line" | cut -d"|" -f4)
    sed -i "s/^${cid}|${cname}|${cnum}|${maxnum}/${cid}|${cname}|$((cnum + 1))|${maxnum}/" "$COURSE_FILE"

    added+="$cid - $cname\n"
  done

  dialog --title "✅ 选课成功" --msgbox "以下课程已成功添加:\n$added" 12 60
}



# 学生查看信息
student_view_info() {
  local user=$1
  local selected_file="$BASE_DIR/selected_courses_${user}.txt"

  # 获取学生信息
  local info_line
  info_line=$(grep "|${user}$" "$BASE_DIR/students.txt")
  if [ -z "$info_line" ]; then
    dialog --title "❌ 用户信息错误" --msgbox "未找到用户信息，请联系管理员。" 7 50
    return
  fi

  local sno=$(echo "$info_line" | cut -d"|" -f1)
  local name=$(echo "$info_line" | cut -d"|" -f2)

  # 获取课程列表
  local course_names=""
  if [ -f "$selected_file" ] && [ -s "$selected_file" ]; then
    while read -r cid; do
      local cname=$(grep "^${cid}|" "$COURSE_FILE" | cut -d"|" -f2)
      [ -n "$cname" ] && course_names+="    ✅ $cname\n"
    done < "$selected_file"
  else
    course_names="    ⚠️ 暂无已选课程\n"
  fi

  # 构造漂亮的信息框
    local display_text=""
    display_text+="📌 学号：$sno\n"
    display_text+="👤 姓名：$name\n\n"
    display_text+="📚 已选课程：\n$course_names\n"
    display_text+="───────────────────────────────\n"
    display_text+="提示：是否需要修改您的学号与姓名？"


  dialog --title "🎓 学生信息" --yesno "$display_text" 22 60
  if [ $? -ne 0 ]; then
    log_action "$user" "查看学生信息"
    return
  fi

  # 使用 form 修改
  local form_output
  form_output=$(dialog --title "📝 修改信息" --form "请修改以下信息：" 15 60 2 \
    "📌 学号：" 1 1 "$sno" 1 12 30 0 \
    "👤 姓名：" 2 1 "$name" 2 12 30 0 \
    3>&1 1>&2 2>&3)

  [ $? -ne 0 ] && dialog --title "取消" --msgbox "信息修改已取消。" 6 40 && return

  local new_sno=$(echo "$form_output" | sed -n 1p)
  local new_name=$(echo "$form_output" | sed -n 2p)

  if [ -z "$new_sno" ] || [ -z "$new_name" ]; then
    dialog --title "⚠️ 输入错误" --msgbox "不能为空，请重新输入。" 6 40
    return
  fi

  # 更新信息
  sed -i "s/^${sno}|${name}|${user}$/${new_sno}|${new_name}|${user}/" "$BASE_DIR/students.txt"
  STUDENT_INFO[$user]="${new_sno}|${new_name}"

  dialog --title "✅ 修改成功" --msgbox "您的信息已更新：\n\n📌 学号：$new_sno\n👤 姓名：$new_name" 8 50
  log_action "$user" "修改信息：学号 $sno → $new_sno，姓名 $name → $new_name"
}




# 教师添加课程
teacher_add_course() {
  local user=$1
  local cid cname maxnum

  cid=$(dialog --clear --inputbox "请输入课程编号（如C004）：" 8 40 3>&1 1>&2 2>&3)
  [ -z "$cid" ] && return
  if grep -q "^${cid}|" "$COURSE_FILE"; then
    dialog --msgbox "课程编号已存在！" 6 30
    log_action "$user" "添加课程失败，编号重复：$cid"
    return
  fi

  cname=$(dialog --clear --inputbox "请输入课程名称：" 8 40 3>&1 1>&2 2>&3)
  [ -z "$cname" ] && return

  while true; do
    maxnum=$(dialog --clear --inputbox "请输入最大选课人数（正整数）：" 8 40 3>&1 1>&2 2>&3)
    if [[ -z "$maxnum" ]]; then
      return
    elif ! [[ "$maxnum" =~ ^[1-9][0-9]*$ ]]; then
      dialog --msgbox "请输入有效的正整数！" 6 40
    else
      break
    fi
  done

  echo "${cid}|${cname}|0|${maxnum}" >> "$COURSE_FILE"
  dialog --msgbox "添加课程成功！" 6 30
  log_action "$user" "添加课程成功：$cid $cname 最大人数：$maxnum"
}
# 教师删除课程
teacher_delete_course() {
  local user=$1
  local courses=()
  while IFS="|" read -r cid cname cnum; do
    courses+=("$cid" "$cname")
  done < "$COURSE_FILE"

  local choice
  choice=$(dialog --clear --menu "请选择要删除的课程：" 15 50 6 "${courses[@]}" 3>&1 1>&2 2>&3)
  [ -z "$choice" ] && return

  sed -i "/^${choice}|/d" "$COURSE_FILE"
  for f in "$BASE_DIR"/selected_courses_*.txt; do
    [ -f "$f" ] && sed -i "/^${choice}$/d" "$f"
  done

  dialog --msgbox "删除课程成功！" 6 30
  log_action "$user" "删除课程成功：$choice"
}

# 教师查看课程
teacher_view_course() {
  local user=$1
  local courses=()
  while IFS="|" read -r cid cname cnum; do
    courses+=("$cid" "$cname")
  done < "$COURSE_FILE"

  local choice
  choice=$(dialog --clear --menu "请选择要查看的课程：" 15 50 6 "${courses[@]}" 3>&1 1>&2 2>&3)
  [ -z "$choice" ] && return

  local line=$(grep "^${choice}|" "$COURSE_FILE")
  local cname=$(echo "$line" | cut -d"|" -f2)
  local cnum=$(echo "$line" | cut -d"|" -f3)

  dialog --msgbox "课程编号: $choice\n课程名称: $cname\n选课人数: $cnum" 8 40
  log_action "$user" "查看课程：$choice"
}

# 系统准备
system_prep() {
  if ! command -v dialog &>/dev/null; then
    echo "请先安装 dialog 命令：sudo yum install dialog -y"
    exit 1
  fi
  init_courses
  init_students_file
  touch "$LOG_FILE"
}

# 主入口
main() {
  system_prep
  login_menu
}

main
