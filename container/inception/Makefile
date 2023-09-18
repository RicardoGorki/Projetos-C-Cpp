all:
	clear && cd ./srcs &&  docker compose up -d

build:
	clear && cd ./srcs/requirements/mariadb &&  docker build -t alpine:3.17-stable .

s:
	clear && docker ps -a

i:
	clear &&  docker images

maria:
	clear &&  docker exec -it 8ae53b86fc38 mariadb -u root -p root

clean:
	clear && cd ./srcs &&  docker compose down && docker image prune -a -f
