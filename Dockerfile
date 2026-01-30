FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    dos2unix \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir -p src && \
    for f in Graph.cpp Graph.h Algorithms.cpp Algorithms.h; do \
        if [ -f "$f" ]; then mv "$f" src/; fi; \
    done

RUN mkdir -p data && \
    for f in input_*.txt; do \
        if [ -f "$f" ]; then mv "$f" data/; fi; \
    done

RUN dos2unix tests/run_tests.sh && \
    chmod +x tests/run_tests.sh

RUN mkdir -p build && cd build && \
    cmake .. && \
    cmake --build .

ENTRYPOINT ["./build/graph_search"]
CMD ["--help"]