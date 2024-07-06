#!/bin/bash

#if [ ! -d "var/www/html"]; then
#	mkdir var/www/
#	mkdir var/www/html
#fi

mkdir var/www/
mkdir var/www/html

cd /var/www/html/

rm -rf *

# install wp-cli
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root

cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

sed -i -r "s/database_name_here/$DB_NAME/1" /var/www/html/wp-config.php
sed -i -r "s/username_here/$MYSQL_USER/1" /var/www/html/wp-config.php
sed -i -r "s/password_here/$MYSQL_PASSWORD/1" /var/www/html/wp-config.php
sed -i -r "s/localhost/mariadb/1" /var/www/html/wp-config.php

wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root

wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PASSWORD --allow-root

wp theme install twentytwentytwo --activate --allow-root

wp plugin update --all --allow-root
sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf

mkdir /run/php

/usr/sbin/php-fpm7.4 -F -R
