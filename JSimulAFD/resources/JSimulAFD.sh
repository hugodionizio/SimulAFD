# Criação da Pasta de binários "bin"
mkdir bin

# Compilação e verificação da biblioteca em C
cd resources/
#gcc -o bin/CSimulAFD.bin -w mainCSimulAFD.c terminal.c Automato.c Estado.c Alfabeto.c Transicao.c busca.c -lm
gcc -fPIC -c -w CSimulAFD.c terminal.c Automato.c Estado.c Alfabeto.c Transicao.c busca.c -lm
gcc -shared -o bin/CSimulAFD.so CSimulAFD.o terminal.o Automato.o Estado.o Alfabeto.o Transicao.o busca.o -lm
rm *.o
nm bin/CSimulAFD.so

# Importação da biblioteca jna.jar
cp resources/jna.jar bin/jna.jar
cd bin/
jar xvf jna.jar com/
rm jna.jar
cd ..

# Importação da biblioteca jgraphx.jar
cp resources/jgraphx*.jar bin/jgraphx*.jar
cd bin/
jar xvf jgraphx*.jar com/
rm jgraphx*.jar
cd ..

# Compilação do projeto em Java
javac -classpath src/grafo/*.jar src/jna/*.jar src/*.jar src/*.java -d bin/
cp -r src/META-INF bin/META-INF
cd bin
jar cvfm JSimulAFD.jar META-INF/MANIFEST.MF JSimulAFD.class JSimulAFD\$JSimulAFD.class com CSimulAFD.so

# Execução do projeto em jar
java -jar JSimulAFD.jar
