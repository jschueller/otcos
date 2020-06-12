conda
=====

build::

    docker pull condaforge/linux-anvil-comp7
    docker run --entrypoint /bin/bash --rm --volume `pwd`:/io condaforge/linux-anvil-comp7 -c "/io/conda/run_docker_build.sh `id -u` `id -g`"

upload::

    conda install anaconda-client
    conda upload otcos*.bz2

install::

    conda install -c jschueller otcos
