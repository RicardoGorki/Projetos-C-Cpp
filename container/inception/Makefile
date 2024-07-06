all: up

up:
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	docker compose -f ./srcs/docker-compose.yml build
	docker compose -f ./srcs/docker-compose.yml up -d

down:
	docker compose -f ./srcs/docker-compose.yml down

stop:
	docker compose -f ./srcs/docker-compose.yml stop

start:
	docker compose -f ./srcs/docker-compose.yml start

show:
	clear && docker ps -a

re: down up

fclean:
	clear && cd ./srcs && docker compose down && docker system prune --all --force --volumes

.PHONY: all up down re start stop show fclean
