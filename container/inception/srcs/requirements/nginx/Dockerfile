# syntax=docker/dockerfile:1

FROM debian:bullseye

RUN apt update && apt install -y --no-install-recommends \
	openssl \
	nginx \
	&& rm -rf /var/lib/apt/lists/*

COPY tools/init_nginx.sh /

CMD ["./init_nginx.sh"]
