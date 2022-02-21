file=$1
output=$2
echo "compiling $1 source into $2"
g++ gui/Graph.cpp gui/Window.cpp gui/GUI.cpp gui/Simple_window.cpp $file -o $output -I ../libs -Wl,-subsystem,windows -mwindows ../libs/lib/libfltk_images.a ../libs/lib/libfltk_jpeg.a ../libs/lib/libfltk_png.a -lz ../libs/lib/libfltk.a -lole32 -luuid -lcomctl32 -lws2_32
