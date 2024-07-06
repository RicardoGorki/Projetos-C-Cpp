#syntax=docker/dockerfile:1

FROM debian:bullseye

RUN	apt update && apt install -y --no-install-recommends \
	ca-certificates \
	php-fpm \
	php-mysql \
	curl \
	&& rm -rf /var/lib/apt/lists/*

COPY tools/init_wp.sh .

CMD ["./init_wp.sh"]
