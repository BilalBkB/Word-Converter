#!/bin/bash

function build()
{
    local project_folder=$(dirname $0)

    local build_folder=$project_folder/build

    if [[ -e $build_folder ]] && [[ "$1" == "-r"  ]]; then
        rm -rf $build_folder;
    fi
    
    if [[ ! -e $build_folder ]]; then
        mkdir $build_folder;
    fi
    
    local current_folder=$(pwd)
    
    cd $build_folder
    cmake ..
    make -j$(nproc)

    cd $current_folder
}

build $@
