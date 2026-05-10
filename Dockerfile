FROM ubuntu:22.04 AS builder

# Install compiler C++, Make, dan library ncurses
RUN apt-get update && \
    apt-get install -y g++ make libncurses5-dev libncursesw5-dev

WORKDIR /app

COPY src/ ./src/
COPY makefile ./

RUN make

FROM ubuntu:22.04

# Install library runtime untuk ncurses dan locales (untuk UTF-8)
RUN apt-get update && \
    apt-get install -y libncursesw5 locales && \
    rm -rf /var/lib/apt/lists/*

# Generate locale UTF-8
RUN locale-gen en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LANGUAGE=en_US:en
ENV LC_ALL=en_US.UTF-8

WORKDIR /app

COPY --from=builder /app/kasir .

ENTRYPOINT ["./kasir"]