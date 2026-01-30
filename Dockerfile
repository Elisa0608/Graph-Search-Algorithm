# Multi-stage build pentru o imagine finală mai mică
FROM gcc:latest AS builder

# Instalează CMake
RUN apt-get update && apt-get install -y cmake && \
    rm -rf /var/lib/apt/lists/*

# Setează directorul de lucru
WORKDIR /app

# Copiază toate fișierele proiectului
COPY . .

# Creează directorul src/ și mută fișierele necesare
RUN mkdir -p src && \
    mv Graph.cpp Graph.h Algorithms.cpp Algorithms.h src/ 2>/dev/null || true

# Creează directorul data/ și mută fișierele de input
RUN mkdir -p data && \
    mv input_*.txt data/ 2>/dev/null || true

# Compilează proiectul
RUN mkdir -p build && cd build && \
    cmake .. && \
    cmake --build .

# Stage final - imagine minimă pentru rulare
FROM ubuntu:22.04

WORKDIR /app

# Copiază executabilul compilat
COPY --from=builder /app/build/graph_search .

# Copiaza fisierele de date necesare pentru teste
COPY --from=builder /app/data ./data

# Instaleaza dependentele runtime necesare (libstdc++)
RUN apt-get update && \
    apt-get install -y libstdc++6 && \
    rm -rf /var/lib/apt/lists/*

# Seteaza executabilul ca entry point
ENTRYPOINT ["./graph_search"]

# Argumentele default (pot fi suprascrise la rulare)
CMD ["--help"]
