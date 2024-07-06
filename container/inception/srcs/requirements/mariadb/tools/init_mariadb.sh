#!/bin/bash

chown -R mysql:mysql /var/lib/mysql

service mariadb start

mariadb << EOF
CREATE DATABASE IF NOT EXISTS $DB_NAME CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;

CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';

GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$MYSQL_USER'@'%';

ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' ;

FLUSH PRIVILEGES;
EOF

#CREATE USER IF NOT EXISTS 'lilith'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
#GRANT ALL PRIVILEGES ON *.* to 'lilith'@'localhost' WITH GRANT OPTION;

kill  $(cat /var/run/mysqld/mysqld.pid)

mariadbd
