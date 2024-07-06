# syntax=docker/dockerfile:1

FROM debian:bullseye

RUN apt update && apt install -y --no-install-recommends \
	mariadb-server \
	&& apt clean \
	&& rm -rf /var/lib/apt/lists/* \
	&& chmod -R 755 /var/lib/mysql/

RUN sed -i "s/127.0.0.1/0.0.0.0/g" etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/init_mariadb.sh .

VOLUME [ "/var/lib/mysql" ]

CMD ["./init_mariadb.sh"]
