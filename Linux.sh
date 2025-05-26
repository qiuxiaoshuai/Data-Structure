#!/bin/bash
# У԰��������ϵͳ - Bash �ű���
# ֧���û�Ȩ�޷ּ�����ͨ�û�������Ա��������Ա����ʵ�ֳ�����Ϣ���û�������

# ======================== �û������ļ� ========================
USER_FILE="users.txt"    # �û���Ϣ�洢�ļ�����ʽ���û��� ���� ��ɫ��

# ��ӡ�û���ͷ
print_user_table_header() {
    printf "+-----------------+------------------+-----------------+\n"
    printf "| %-18s | %-18s | %-17s |\n" "�û���" "����" "��ɫ"
    printf "+-----------------+------------------+-----------------+\n"
}

# ��ӡ�����û���Ϣ��
print_user_table() {
    while IFS=' ' read -r username password role; do
        printf "| %-15s | %-16s | %-15s |\n" "$username" "$password" "$role"
    done < "$USER_FILE"
    printf "+-----------------+------------------+-----------------+\n"
}

# �������û�
add_user() {
    echo "���������û���:"
    read new_username
    echo "������������:"
    read new_password
    echo "�������ɫ (1 - ��ͨ�û�, 2 - ����Ա, 3 - ������Ա):"
    read new_role

    echo "$new_username $new_password $new_role" >> "$USER_FILE"
    echo "�û� $new_username ������"
}

# ɾ���û�
delete_user() {
    echo "������Ҫɾ�����û���:"
    read del_username

    temp_file=$(mktemp)
    # ʹ�� grep -v �ų�ָ���û�
    grep -v "^$del_username " "$USER_FILE" > "$temp_file"
    mv "$temp_file" "$USER_FILE"

    echo "�û� $del_username ��ɾ��"
}

# �޸��û�����
modify_user() {
    echo "������Ҫ�޸ĵ��û���:"
    read mod_username
    echo "������������:"
    read new_password

    temp_file=$(mktemp)
    while IFS=' ' read -r username password role; do
        if [[ "$username" == "$mod_username" ]]; then
            # �ҵ��û�����������
            echo "$username $new_password $role" >> "$temp_file"
        else
            echo "$username $password $role" >> "$temp_file"
        fi
    done < "$USER_FILE"
    mv "$temp_file" "$USER_FILE"

    echo "�û� $mod_username �������޸�"
}

# �г������û�
list_users() {
    print_user_table_header
    print_user_table
}

# ======================== ���������ļ� ========================
VEHICLE_FILE="vehicles.txt"   # ������Ϣ�洢�ļ�����ʽΪ CSV: �������,���ƺ���,��������,����Ʒ�Ƽ���ɫ,��������,��ϵ�绰,Υ���¼

# ��ӡ������ͷ
print_vehicle_table_header() {
    printf "+-----------------+-----------------+-----------------+--------------------+--------------------+--------------------+--------------------+\n"
    printf "| %-19s | %-19s | %-19s | %-18s | %-18s | %-18s | %-18s |\n" "�������" "���ƺ���" "��������" "����Ʒ�Ƽ���ɫ" "��������" "��ϵ�绰" "Υ���¼"
    printf "+-----------------+-----------------+-----------------+--------------------+--------------------+--------------------+--------------------+\n"
}

# ���㳵����������ֶγ��ȣ�δ�ã�Ԥ����
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

# ��ӡ���г�����Ϣ��
print_vehicle_table() {
    while IFS=',' read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record; do
        printf "| %-15s | %-15s | %-15s | %-18s | %-18s | %-18s | %-18s |\n" "$vehicle_id" "$license_plate" "$owner_name" "$brand_color" "$owner_dorm" "$contact" "$violation_record"
    done < "$VEHICLE_FILE"
    printf "+-----------------+-----------------+-----------------+--------------------+--------------------+--------------------+--------------------+\n"
}

# ���ӳ�����Ϣ
add_vehicle() {
    echo "�����복�����:"
    read vehicle_id
    echo "�����복�ƺ���:"
    read license_plate
    echo "�����복������:"
    read owner_name
    echo "�����복��Ʒ�Ƽ���ɫ:"
    read brand_color
    echo "�����복������:"
    read owner_dorm
    echo "��������ϵ�绰:"
    read contact
    echo "�����복��Υ���¼:"
    read violation_record

    echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$VEHICLE_FILE"
    echo "������Ϣ��ӳɹ�!"
}

# �޸ĳ���Υ���¼
modify_violation_record() {
    echo "������Ҫ�޸ĵĳ������:"
    read vehicle_id_input

    temp_file=$(mktemp)
    found=0

    while IFS=',' read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record; do
        if [[ "$vehicle_id" == "$vehicle_id_input" ]]; then
            echo "��ǰΥ���¼: $violation_record"
            echo "�������µ�Υ���¼:"
            read new_violation_record
            echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$new_violation_record" >> "$temp_file"
            found=1
        else
            echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$temp_file"
        fi
    done < "$VEHICLE_FILE"

    mv "$temp_file" "$VEHICLE_FILE"

    if [[ $found -eq 1 ]]; then
        echo "Υ���¼�Ѹ��£�"
    else
        echo "δ�ҵ��ó�����š�"
    fi
}

# ɾ��������Ϣ
delete_vehicle() {
    echo "������Ҫɾ���ĳ������:"
    read del_vehicle_id

    temp_file=$(mktemp)
    # ���˵�ָ���������
    grep -v "^$del_vehicle_id," "$VEHICLE_FILE" > "$temp_file"
    mv "$temp_file" "$VEHICLE_FILE"

    echo "���� $del_vehicle_id ��ɾ��"
}

# �޸ĳ�����Ϣ
modify_vehicle() {
    echo "������Ҫ�޸ĵĳ������:"
    read mod_vehicle_id
    mod_vehicle_id=$(echo "$mod_vehicle_id" | tr -d '\r\n[:space:]')

    found=0
    temp_file=$(mktemp)

    # �ȹ��˳���Ŀ�공����������м�¼
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
            # �����Ȳ�д�����油���¼�¼
        else
            echo "$vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$temp_file"
        fi
    done < "$VEHICLE_FILE"

    if [[ $found -eq 1 ]]; then
        # ��ʾ��������Ϣ
        echo "�������³��ƺ��루��: $old_license_plate��:"
        read license_plate
        echo "�������³�����������: $old_owner_name��:"
        read owner_name
        echo "�������³���Ʒ�Ƽ���ɫ����: $old_brand_color��:"
        read brand_color
        echo "�������³������ᣨ��: $old_owner_dorm��:"
        read owner_dorm
        echo "����������ϵ�绰����: $old_contact��:"
        read contact
        echo "��������Υ���¼����: $old_violation_record��:"
        read violation_record

        sed -i "/^$/d" "$temp_file"  # ɾ������
        echo "$mod_vehicle_id,$license_plate,$owner_name,$brand_color,$owner_dorm,$contact,$violation_record" >> "$temp_file"

        mv "$temp_file" "$VEHICLE_FILE"
        echo "������Ϣ�Ѹ��£�"
    else
        rm "$temp_file"
        echo "δ�ҵ��ó�����š�"
    fi
}

# �г����г���
list_vehicles() {
    print_vehicle_table_header
    print_vehicle_table
}

# ��ѯ�����������ƺš��������������ģ��ƥ�䣩
query_vehicle() {
    echo "�����복�ƺ��롢���������������:"
    read search_term

    echo "��ѯ���:"
    while IFS=, read -r vehicle_id license_plate owner_name brand_color owner_dorm contact violation_record; do
        if [[ "$vehicle_id" == *"$search_term"* || "$license_plate" == *"$search_term"* || "$owner_name" == *"$search_term"* ]]; then
            echo "$vehicle_id, $license_plate, $owner_name, $brand_color, $owner_dorm, $contact, $violation_record"
        fi
    done < "$VEHICLE_FILE"
}

# ======================== ����ϵͳ========================
backup_system() {
    echo "���ڱ���ϵͳ����..."
    
    echo "ϵͳ�����ѱ���"
}

# �������Ա�˻������ڣ��Զ�����Ĭ�Ϲ���Ա
create_admin_if_needed() {
    if ! grep -q "admin " "$USER_FILE"; then
        echo "����Ա�˻������ڣ����ڴ���..."
        echo "admin adminpassword 2" >> "$USER_FILE"
        echo "����Ա�˻��Ѵ�����Ĭ�������� adminpassword"
    fi
}

# ======================== ��¼�߼� ========================

username=""  # ��ǰ��¼�û���
role=""      # ��ǰ��¼��ɫ

login() {
    echo "�������û���:"
    read input_username
    echo "����������:"
    read input_password

    # ���û��ļ�����֤�û���������
    while IFS=' ' read -r stored_username stored_password stored_role; do
        if [[ "$stored_username" == "$input_username" && "$stored_password" == "$input_password" ]]; then
            echo "��¼�ɹ���"
            username="$stored_username"
            role="$stored_role"
            return 0   # ��¼�ɹ�
        fi
    done < "$USER_FILE"

    echo "�û�����������������µ�¼��"
    return 1  # ��¼ʧ��
}

# �л��û�
switch_user() {
    echo "������Ҫ�л������û���:"
    read new_username
    echo "����������:"
    read new_password

    # ��֤�û���Ϣ
    while IFS=' ' read -r stored_username stored_password stored_role; do
        if [[ "$stored_username" == "$new_username" && "$stored_password" == "$new_password" ]]; then
            username="$stored_username"
            role="$stored_role"
            echo "�л��ɹ�����ǰ�û���$username����ɫ��$role"
            # ���� 0 ��ʾ�л��ɹ��������߸�����ת�˵�
            return 0
        fi
    done < "$USER_FILE"

    echo "�л�ʧ�ܣ��û������������"
    return 1
}

# ======================== ����ɫ�˵� ========================

# ��ͨ�û��˵�
user_menu() {
    while true; do
        echo ""
        echo "===== ��ͨ�û��˵� ====="
        echo "1. ��ѯ������Ϣ"
        echo "2. �޸ĳ���Υ���¼"
        echo "3. �л��û�"
        echo "4. �˳�"
        echo "������ѡ��:"
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
                    # �л��ɹ����˳���ǰ�˵�ѭ�����ص���ѭ����ת�²˵�
                    break
                fi
                ;;
            4)
                exit 0
                ;;
            *)
                echo "��Чѡ����������롣"
                ;;
        esac
    done
}

# ����Ա�˵�
admin_menu() {
    while true; do
        echo ""
        echo "===== ����Ա�˵� ====="
        echo "1. �����û�"
        echo "2. ɾ���û�"
        echo "3. �޸��û�����"
        echo "4. �г������û�"
        echo "5. ���ӳ���"
        echo "6. ɾ������"
        echo "7. �޸ĳ�����Ϣ"
        echo "8. �г����г���"
        echo "9. ����ϵͳ"
        echo "10. �л��û�"
        echo "11. �˳�"
        echo "������ѡ��:"
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
                    # �л��ɹ����˳��˵�ѭ������ת�²˵�
                    break
                fi
                ;;
            11)
                exit 0
                ;;
            *)
                echo "��Чѡ����������롣"
                ;;
        esac
    done
}

# ������Ա�˵�
security_menu() {
    while true; do
        echo ""
        echo "===== ������Ա�˵� ====="
        echo "1. ��ѯ������Ϣ"
        echo "2. �޸ĳ���Υ���¼"
        echo "3. �л��û�"
        echo "4. �˳�"
        echo "������ѡ��:"
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
                echo "��Чѡ����������롣"
                ;;
        esac
    done
}

# ======================== ��������� ========================

create_admin_if_needed

while true; do
    # ��¼�ɹ�����ݽ�ɫ��ת��Ӧ�˵�
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
                echo "δ֪��ɫ���˳���"
                exit 1
                ;;
        esac
    else
        echo "��¼ʧ�ܣ������³��ԡ�"
    fi
done
