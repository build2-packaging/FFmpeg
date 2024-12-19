sed -nE '/#if(.*)/,/#endif/p' ../conditional_source.c \
  | awk '/#if/{flag=1; block=""; match($0, /#if[ \t]+([A-Za-z0-9_]+)/, arr); condition=arr[1]} flag{block=block $0 "\n"} /#endif/{flag=0; print "#include \"config_components.h\"\n" block > (condition ".c")}'
