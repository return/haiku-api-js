set -e

# Install the custom nbind dependency first before building.
if [ -d "third_party/nbind/node_modules" ]; then
	true
else
   cd third_party/nbind/ ; npm install ; cd ../../
fi

npm run -- node-gyp configure
sed -i "s,-pthread,-fPIC,g" build/nbind.target.mk
sed -i "s,-rdynamic,-fPIC,g" build/nbind.target.mk

npm run -- node-gyp build
