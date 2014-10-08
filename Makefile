all: pch

pch:
	test -f proj.ios_mac/ios/Prefix.pch || touch proj.ios_mac/ios/Prefix.pch
	test -f proj.ios_mac/mac/Prefix.pch || touch proj.ios_mac/mac/Prefix.pch

