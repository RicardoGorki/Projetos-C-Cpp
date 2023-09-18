#!/bin/bash

mariadb << EOF

create database wordpress;
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON * . * TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
exit
EOF


