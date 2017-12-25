#!/usr/bin/env bash
ctest -R "Test$"; gcovr -b --root=.. --html --html-details --output=coverage.html --delete --exclude=_common
