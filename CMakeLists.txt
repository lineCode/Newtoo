cmake_minimum_required(VERSION 2.6)

project(Newtoo)

add_executable(
    Newtoo 
         src/Newtoo.cpp
		 src/html/ht_active_id_table.cpp
		 src/html/ht_active_id_table.h
		 src/html/ht_attribute.cpp
		 src/html/ht_attribute.h
		 src/html/ht_identifier.cpp
		 src/html/ht_identifier.h
		 src/html/ht_parser.cpp
		 src/html/ht_parser.h
		 src/html/ht_parser_output.cpp
		 src/html/ht_parser_output.h
		 src/html/ht_region.cpp
		 src/html/ht_region.h
		 src/html/ht_token.cpp
		 src/html/ht_token.h
		 src/utils/garbage_collector.cpp
		 src/utils/garbage_collector.h
		 src/utils/gc_object.cpp
		 src/utils/gc_object.h
		 src/utils/gc_ptr.cpp
		 src/utils/gc_ptr.h
		 src/utils/string_switch.h
)
