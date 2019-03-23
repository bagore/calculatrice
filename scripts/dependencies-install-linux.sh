#!/bin/bash

# To stop at first error
set -e

# To trace executed commands
set -x



#
#   Installation of needed dependencies
#
echo "No dependencies to install."

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
