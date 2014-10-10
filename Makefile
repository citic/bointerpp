all: pch

pch:
	test -f proj.ios_mac/ios/Prefix.pch || touch proj.ios_mac/ios/Prefix.pch
	test -f proj.ios_mac/mac/Prefix.pch || touch proj.ios_mac/mac/Prefix.pch

sourcefiles:
	echo 'set(COMMON_SRC' > SourceFiles.txt
	find Classes -name '*.cpp' -exec echo '    '{} \; >> SourceFiles.txt
	echo ')' >> SourceFiles.txt
	echo >> SourceFiles.txt
	echo 'set(COMMON_INCLUDE' >> SourceFiles.txt
	find Classes -type d -exec echo '    $${CMAKE_SOURCE_DIR}/'{} \; >> SourceFiles.txt
	echo ')' >> SourceFiles.txt
