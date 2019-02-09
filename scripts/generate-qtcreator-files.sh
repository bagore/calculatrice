#!/bin/bash

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

PROJECT_ROOT="$( cd "$(dirname "$0")" && cd .. && pwd -P )"
PROJECT_NAME="$(basename ${PROJECT_ROOT})"

echo "Project name : $PROJECT_NAME"


function	config_config_createIfNotExists()
{
	lFileName="${PROJECT_ROOT}/${PROJECT_NAME}.config"

	if [ ! -e "${lFileName}" ]
	then
		cat << EOT > "${lFileName}"
// Add predefined macros for your project here. For example:
// #define THE_ANSWER 42
EOT
	fi
}



function	config_creator_createIfNotExists()
{
	lFileName="${PROJECT_ROOT}/${PROJECT_NAME}.creator"

	if [ ! -e "${lFileName}" ]
	then
		cat << EOT > "${lFileName}"
[General]
EOT
	fi
}



function	config_files_createOrUpdate()
{
	lFileName="${PROJECT_ROOT}/${PROJECT_NAME}.files"

	echo "Makefile" > "${lFileName}"

	find doc/ inc/ rsrc/ src/ tests/ -type f >> "${lFileName}"
}


function	config_includes_ifNotExists()
{
	lFileName="${PROJECT_ROOT}/${PROJECT_NAME}.includes"

	if [ ! -e "${lFileName}" ]
	then
		echo "inc/" >> "${lFileName}"
		echo "src/" >> "${lFileName}"
		echo "tests/" >> "${lFileName}"
	fi
}


#
#   Main
#
pushd "${PROJECT_ROOT}"
	config_config_createIfNotExists
	config_creator_createIfNotExists
	config_files_createOrUpdate
	config_includes_ifNotExists
popd
