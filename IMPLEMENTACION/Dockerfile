# Usamos una base de Ubuntu (Linux)
FROM ubuntu:latest

# Evitar preguntas interactivas durante la instalación
ENV DEBIAN_FRONTEND=noninteractive

# Instalar herramientas necesarias para Procesadores del Lenguaje
# He añadido gforth a la lista
RUN apt-get update && apt-get install -y \
    build-essential \
    flex \
    bison \
    clisp \
    gforth \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Definir el directorio de trabajo dentro del contenedor
# Nota: He cambiado /home/practica a /work para que coincida 
# con los comandos que hemos usado antes, pero puedes dejarlo como prefieras.
WORKDIR /work

# Comando por defecto al arrancar el contenedor
CMD ["/bin/bash"]