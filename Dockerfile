FROM yg397/thrift-microservice-deps:xenial

ARG NUM_CPUS=4

COPY ./ /vending-machine-microservices
RUN cd /vending-machine-microservices \
    && mkdir -p build \
    && cd build \
    && cmake .. \
    && make -j${NUM_CPUS} \
    && make install

RUN ls -l /usr/local/bin # Verify installation
RUN chmod +x /usr/local/bin/BeveragePreferenceService # Add execute permissions
ENV PATH="$PATH:/usr/local/bin"

WORKDIR /vending-machine-microservices
