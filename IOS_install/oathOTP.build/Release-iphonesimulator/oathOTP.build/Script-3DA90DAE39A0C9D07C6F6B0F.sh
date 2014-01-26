#!/bin/sh
for f in $(find ${OBJECT_FILE_DIR}-${CURRENT_VARIANT}/${CURRENT_ARCH} -name '*.o'); do (nm $f | grep -q 'T _main' && cp $f $f.original && ld -r -alias _main _qt_main -unexported_symbol _main $f.original -o $f) || true ; done
