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

sources=Split('main.cpp cell.cpp game.cpp state.cpp change.cpp')
Library('foo',['cell.hpp', 'state.hpp', 'change.hpp'])

app = env.Program(target = "test", source = sources, LIBS = ['foo'])
env.Default(app)