apt-get update                                                     
apt-get install -y g++ build-essential cmake git curl

mkdir -p /usr/
mkdir -p /opt/mercury/inc
mkdir -p /opt/mercury/src
mkdir -p /opt/mercury/test
mkdir -p /opt/build/boost

curl -L https://dl.bintray.com/boostorg/release/1.74.0/source/boost_1_74_0.tar.gz -o boost_1_74_0.tar.gz                                      && \
tar -xzf boost_1_74_0.tar.gz --directory /opt/build/boost
cd /opt/build/boost/boost_1_74_0
./bootstrap.sh --prefix=/usr/ --with-libraries=system,filesystem,test
./b2 -j 2 install                                                  
ldconfig