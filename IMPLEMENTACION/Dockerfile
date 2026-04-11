# Usamos una base de Ubuntu (Linux)
FROM ubuntu:latest

# Evitar preguntas interactivas durante la instalación
ENV DEBIAN_FRONTEND=noninteractive

# Instalar herramientas necesarias para Procesadores del Lenguaje
RUN apt-get update && apt-get install -y \
    build-essential \
    flex \
    bison \
    clisp \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Definir el directorio de trabajo dentro del contenedor
WORKDIR /home/practica