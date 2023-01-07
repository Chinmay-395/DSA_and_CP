/*
	                                           f(0,[])
	                          /                                  \
	                     f(1,[3])                               f(1,[])
	                  /         \                         /                     \
	         f(2,[3,1])         f(2,[3])              f(2,[1])               f(2,[])
	         /     \          /         \             |      \              /      \
	f(3,[3,1,2])  f(3,[3,1]) f(3,[3,2]) f(3,[3]) f(3,[1,2])  f(3,[1])   f(3,[2])  f(3,[])
	              
	              for any string there would be 2^n subsequences where n is size of the string 
*/


