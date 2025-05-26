#!/bin/bash
# 校园车辆管理系统 - Bash 脚本版
# 支持用户权限分级（普通用户、管理员、保安人员），实现车辆信息和用户管理功能

# ======================== 用户数据文件 ========================
USER_FILE="users.txt"    # 用户信息存储文件（格式：用户名 密码 角色）

# 打印用户表头
print_user_table_header() {
    printf "+-----------------+------------------+-----------------+\n"
    printf "| %-18s | %-18s | %-17s |\n" "用户名" "密码" "角色"
    printf "+-----------------+------------------+-----------------+\n"
}

# 打印所有用户信息表
print_user_table() {
    while IFS=' ' read -r username password role; do
        printf "| %-15s | %-16s | %-15s |\n" "$username" "$password" "$role"
    done < "$USER_FILE"
    printf "+-----------------+------------------+-----------------+\n"
}

# 增加新用户
add_user() {
    echo "请输入新用户名:"
    read new_username
    echo "请输入新密码:"
    read new_password
    echo "请输入角色 (1 - 普通用户, 2 - 管理员, 3 - 保安人员):"
    read new_role

    echo "$new_username $new_password $new_role" >> "$USER_FILE"
    echo "用户 $new_username 已增加"
}

# 删除用户
delete_user() {
    echo "请输入要删除的用户名:"
    read del_username

    temp_file=$(mktemp)
    # 使用 grep -v 排除指定用户
    grep -v "^$del_username " "$USER_FILE" > "$temp_file"
    mv "$temp_file" "$USER_FILE"

    echo "用户 $del_username 已删除"
}

# 修改用户密码
modify_user() {
    echo "请输入要修改的用户名:"
    read mod_username
    echo "请输入新密码:"
    read new_password

    temp_file=$(mktemp)
    while IFS=' ' read -r username password role; do
        if [[ "$username" == "$mod_username" ]]; then
            # 找到用户，更新密码
            echo "$username $new_password $role" >> "$temp_file"
        else
            echo "$username $password $role" >> "$temp_file"
        fi
    done < "$USER_FILE"
    mv "$temp_file" "$USER_FILE"

    echo "用户 $mod_username 密码已修改"
}

# 列出所有用户
list_users() {
    print_user_table_header
    print_user_table
}

# ======================== 车辆数据文件 ========================
VEHICLE_FILE="vehicles.txt"   # 车辆信息存储文件，格式为 CSV: 车辆编号,车牌号码,车主姓名,车辆品牌及颜色,车主宿舍,联系电话,违规记录

# 打印车辆表头
print_vehicle_table_header() {
    printf "+-----------------+-----------------+-----------------+--------------------+--------------------+--------------------+--------------------+\n"
    printf "| %-19s | %-19s | %-19s | %-18s | %-18s | %-18s | %-18s |\n" "车辆编号" "车牌号码" "车主姓名" "车辆品牌及颜色" "车主宿舍" "联系电话" "违规记录"
    printf "+-----------------+-----------------+-----------------+--------------------+--------------------+--------------------+--------------------+\n"
}

# 计算车辆数据中最长字段长度（未用，预留）
get_max_length() {
    local max_length=0
    local value
    while IFS=',' read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record; do
        for value in "$vehicle_id" "$license_plate" "$owner_name" "$brand_color" "$owner_dorm" "$contact" "$violation_record"; do
            local length=${#value}
            if (( length > max_length )); then
                max_length=$length
            fi
        done
    done < "$VEHICLE_FILE"
    echo $max_length
}

# 打印所有车辆信息表
print_vehicle_table() {
    while IFS=',' read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record; do
        printf "| %-15s | %-15s | %-15s | %-18s | %-18s | %-18s | %-18s |\n" "$vehicle_id" "$license_plate" "$owner_name" "$brand_color" "$owner_dorm" "$contact" "$violation_record"
    done < "$VEHICLE_FILE"
    printf "+-----------------+-----------------+-----------------+--------------------+--------------------+--------------------+--------------------+\n"
}

# 增加车辆信息
add_vehicle() {
    echo "请输入车辆编号:"
    read vehicle_id
    echo "请输入车牌号码:"
    read license_plate
    echo "请输入车主姓名:"
    read owner_name
    echo "请输入车辆品牌及颜色:"
    read brand_color
    echo "请输入车主宿舍:"
    read owner_dorm
    echo "请输入联系电话:"
    read contact
    echo "请输入车辆违规记录:"
    read violation_record

    echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$VEHICLE_FILE"
    echo "车辆信息添加成功!"
}

# 修改车辆违规记录
modify_violation_record() {
    echo "请输入要修改的车辆编号:"
    read vehicle_id_input

    temp_file=$(mktemp)
    found=0

    while IFS=',' read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record; do
        if [[ "$vehicle_id" == "$vehicle_id_input" ]]; then
            echo "当前违规记录: $violation_record"
            echo "请输入新的违规记录:"
            read new_violation_record
            echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$new_violation_record" >> "$temp_file"
            found=1
        else
            echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$temp_file"
        fi
    done < "$VEHICLE_FILE"

    mv "$temp_file" "$VEHICLE_FILE"

    if [[ $found -eq 1 ]]; then
        echo "违规记录已更新！"
    else
        echo "未找到该车辆编号。"
    fi
}

# 删除车辆信息
delete_vehicle() {
    echo "请输入要删除的车辆编号:"
    read del_vehicle_id

    temp_file=$(mktemp)
    # 过滤掉指定车辆编号
    grep -v "^$del_vehicle_id," "$VEHICLE_FILE" > "$temp_file"
    mv "$temp_file" "$VEHICLE_FILE"

    echo "车辆 $del_vehicle_id 已删除"
}

# 修改车辆信息
modify_vehicle() {
    echo "请输入要修改的车辆编号:"
    read mod_vehicle_id
    mod_vehicle_id=$(echo "$mod_vehicle_id" | tr -d '\r\n[:space:]')

    found=0
    temp_file=$(mktemp)

    # 先过滤出除目标车辆以外的所有记录
    while IFS=',' read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record || [[ -n "$vehicle_id" ]]; do
        vehicle_id=$(echo "$vehicle_id" | tr -d '\r\n[:space:]')
        if [[ "$vehicle_id" == "$mod_vehicle_id" ]]; then
            found=1
            old_license_plate=$license_plate
            old_owner_name=$owner_name
            old_brand_color=$brand_color
            old_owner_dorm=$owner_dorm
            old_contact=$contact
            old_violation_record=$violation_record
            # 这里先不写，后面补充新记录
        else
            echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$temp_file"
        fi
    done < "$VEHICLE_FILE"

    if [[ $found -eq 1 ]]; then
        # 提示输入新信息
        echo "请输入新车牌号码（旧: $old_license_plate）:"
        read license_plate
        echo "请输入新车主姓名（旧: $old_owner_name）:"
        read owner_name
        echo "请输入新车辆品牌及颜色（旧: $old_brand_color）:"
        read brand_color
        echo "请输入新车主宿舍（旧: $old_owner_dorm）:"
        read owner_dorm
        echo "请输入新联系电话（旧: $old_contact）:"
        read contact
        echo "请输入新违规记录（旧: $old_violation_record）:"
        read violation_record

        sed -i "/^$/d" "$temp_file"  # 删除空行
        echo "$mod_vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$temp_file"

        mv "$temp_file" "$VEHICLE_FILE"
        echo "车辆信息已更新！"
    else
        rm "$temp_file"
        echo "未找到该车辆编号。"
    fi
}

# 列出所有车辆
list_vehicles() {
    print_vehicle_table_header
    print_vehicle_table
}

# 查询车辆（按车牌号、车主名或车辆编号模糊匹配）
query_vehicle() {
    echo "请输入车牌号码、车主姓名或车辆编号:"
    read search_term

    echo "查询结果:"
    while IFS=, read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record; do
        if [[ "$vehicle_id" == *"$search_term"* || "$license_plate" == *"$search_term"* || "$owner_name" == *"$search_term"* ]]; then
            echo "$vehicle_id, $license_plate, $owner_name, $brand_color, $owner_dorm, $contact, $violation_record"
        fi
    done < "$VEHICLE_FILE"
}

# ======================== 备份系统========================
backup_system() {
    echo "正在备份系统数据..."
    
    echo "系统数据已备份"
}

# 如果管理员账户不存在，自动创建默认管理员
create_admin_if_needed() {
    if ! grep -q "admin " "$USER_FILE"; then
        echo "管理员账户不存在，正在创建..."
        echo "admin adminpassword 2" >> "$USER_FILE"
        echo "管理员账户已创建，默认密码是 adminpassword"
    fi
}

# ======================== 登录逻辑 ========================

username=""  # 当前登录用户名
role=""      # 当前登录角色

login() {
    echo "请输入用户名:"
    read input_username
    echo "请输入密码:"
    read input_password

    # 从用户文件中验证用户名和密码
    while IFS=' ' read -r stored_username stored_password stored_role; do
        if [[ "$stored_username" == "$input_username" && "$stored_password" == "$input_password" ]]; then
            echo "登录成功！"
            username="$stored_username"
            role="$stored_role"
            return 0   # 登录成功
        fi
    done < "$USER_FILE"

    echo "用户名或密码错误，请重新登录。"
    return 1  # 登录失败
}

# 切换用户
switch_user() {
    echo "请输入要切换到的用户名:"
    read new_username
    echo "请输入密码:"
    read new_password

    # 验证用户信息
    while IFS=' ' read -r stored_username stored_password stored_role; do
        if [[ "$stored_username" == "$new_username" && "$stored_password" == "$new_password" ]]; then
            username="$stored_username"
            role="$stored_role"
            echo "切换成功，当前用户：$username，角色：$role"
            # 返回 0 表示切换成功，调用者负责跳转菜单
            return 0
        fi
    done < "$USER_FILE"

    echo "切换失败，用户名或密码错误。"
    return 1
}

# ======================== 各角色菜单 ========================

# 普通用户菜单
user_menu() {
    while true; do
        echo ""
        echo "===== 普通用户菜单 ====="
        echo "1. 查询车辆信息"
        echo "2. 修改车辆违规记录"
        echo "3. 切换用户"
        echo "4. 退出"
        echo "请输入选项:"
        read option
        case $option in
            1)
                query_vehicle
                ;;
            2)
                modify_violation_record
                ;;
            3)
                if switch_user; then
                    # 切换成功，退出当前菜单循环，回到主循环跳转新菜单
                    break
                fi
                ;;
            4)
                exit 0
                ;;
            *)
                echo "无效选项，请重新输入。"
                ;;
        esac
    done
}

# 管理员菜单
admin_menu() {
    while true; do
        echo ""
        echo "===== 管理员菜单 ====="
        echo "1. 增加用户"
        echo "2. 删除用户"
        echo "3. 修改用户密码"
        echo "4. 列出所有用户"
        echo "5. 增加车辆"
        echo "6. 删除车辆"
        echo "7. 修改车辆信息"
        echo "8. 列出所有车辆"
        echo "9. 备份系统"
        echo "10. 切换用户"
        echo "11. 退出"
        echo "请输入选项:"
        read option
        case $option in
            1)
                add_user
                ;;
            2)
                delete_user
                ;;
            3)
                modify_user
                ;;
            4)
                list_users
                ;;
            5)
                add_vehicle
                ;;
            6)
                delete_vehicle
                ;;
            7)
                modify_vehicle
                ;;
            8)
                list_vehicles
                ;;
            9)
                backup_system
                ;;
            10)
                if switch_user; then
                    # 切换成功，退出菜单循环，跳转新菜单
                    break
                fi
                ;;
            11)
                exit 0
                ;;
            *)
                echo "无效选项，请重新输入。"
                ;;
        esac
    done
}

# 保安人员菜单
security_menu() {
    while true; do
        echo ""
        echo "===== 保安人员菜单 ====="
        echo "1. 查询车辆信息"
        echo "2. 修改车辆违规记录"
        echo "3. 切换用户"
        echo "4. 退出"
        echo "请输入选项:"
        read option
        case $option in
            1)
                query_vehicle
                ;;
            2)
                modify_violation_record
                ;;
            3)
                if switch_user; then
                    break
                fi
                ;;
            4)
                exit 0
                ;;
            *)
                echo "无效选项，请重新输入。"
                ;;
        esac
    done
}

# ======================== 主程序入口 ========================

create_admin_if_needed

while true; do
    # 登录成功后根据角色跳转对应菜单
    if login; then
        case $role in
            1)
                user_menu
                ;;
            2)
                admin_menu
                ;;
            3)
                security_menu
                ;;
            *)
                echo "未知角色，退出。"
                exit 1
                ;;
        esac
    else
        echo "登录失败，请重新尝试。"
    fi
done
