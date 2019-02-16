#!/bin/bash

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

PROJECT_ROOT="$( cd "$(dirname "$0")" && cd .. && pwd -P )"
PROJECT_NAME="$(basename ${PROJECT_ROOT})"

archivePrefix=$1


archive_name="${PROJECT_NAME}"

if [ ! -z ${archivePrefix} ]
then
	archive_name="${archivePrefix}_${archive_name}"
fi

archive_name="${archive_name}_$(date '+%Y%M%d_%H%m%S').zip"

echo "$archive_name"
# Clean project dir
pushd ${PROJECT_ROOT}
	make distclean
	cd ..
	zip -r "${archive_name}" "${PROJECT_NAME}"
#popd

exit $?
