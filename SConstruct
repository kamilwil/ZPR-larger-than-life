import os

env = Environment()
boost_prefix = ""
if os.name=='nt':
  boost_prefix = "C:\BOOST\boost"
else:
  boost_prefix = "/usr" # or wherever you installed boost
sources = env.Glob("*.cpp")
env.Append(CPPPATH = [os.path.join(boost_prefix, "include")])
env.Append(LIBPATH = [os.path.join(boost_prefix, "lib")])
env.Append(CXXFLAGS = '-std=c++11')

Library('foo',['cell.hpp','game.hpp' 'state.hpp', 'change.hpp'])

app = env.Program(target = "test", source = sources)
env.Default(app)