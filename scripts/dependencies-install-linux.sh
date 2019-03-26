#!/bin/bash

# To stop at first error
set -e

# To trace executed commands
set -x



#
#   Installation of needed dependencies
#

# C++14 - see https://gist.github.com/cotsog/3ce84675af0d74438d91#gistcomment-2027135
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq
sudo apt-get install -qq g++-6
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90

#sudo apt update  --allow-unauthenticated --allow-insecure-repositories

#sudo apt install -y <package>

#sudo apt-key adv --fetch-keys http://repos.codelite.org/CodeLite.asc
#sudo apt-add-repository -y 'deb http://repos.codelite.org/wx3.1.2/ubuntu/ xenial universe'
#sudo apt update --allow-unauthenticated --allow-insecure-repositories
#sudo apt-get install libwxbase3.1-0-unofficial3 \
#       libwxbase3.1unofficial3-dev \
#       libwxgtk3.1-0-unofficial3 \
#       libwxgtk3.1unofficial3-dev \
#       wx3.1-headers \
#       wx-common

sudo apt install -y \
	libwxgtk3.0-dev \
	libwxbase3.0-dev \
	libwxgtk3.0-0 \
	wx-common



exit $?
