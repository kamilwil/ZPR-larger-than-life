import os

env = Environment()
boost_prefix = ""
if os.name=='nt':
  boost_prefix = "C:\BOOST\boost"
else:
  boost_prefix = "/usr/lib/boost"
sources = env.Glob("src/ZPR-larger-than-life/*.cpp")
env.Append(CPPPATH = [os.path.join(boost_prefix, "include")])
env.Append(LIBPATH = [os.path.join(boost_prefix, "lib")])
env.Append(CXXFLAGS = '-std=c++11')

Library('foo',['src/ZPR-larger-than-life/cell.hpp','src/ZPR-larger-than-life/game.hpp' 'src/ZPR-larger-than-life/state.hpp', 'src/ZPR-larger-than-life/change.hpp', 'src/ZPR-larger-than-life/rules.hpp'])

app = env.Program(target = "build/test", source = sources)
env.Default(app)
