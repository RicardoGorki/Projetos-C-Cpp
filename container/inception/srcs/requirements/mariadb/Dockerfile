FROM debian:bullseye

RUN apt update && apt upgrade -y
RUN apt install -y mariadb-server
RUN service mariadb restart
WORKDIR /app
COPY /conf/script.sh .
RUN chmod +x script.sh

ARG MYSQL_ROOT_PASSWORD
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ENV MYSQL_ROOT_PASSWORD ${MYSQL_ROOT_PASSWORD}
ENV MYSQL_USER ${MYSQL_USER}
ENV MYSQL_PASSWORD ${MYSQL_PASSWORD}

EXPOSE 3306





RUN  service mariadb restart && "./script.sh"

CMD ["mysqld"]
