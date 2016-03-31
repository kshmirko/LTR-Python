from distutils.core import setup, Extension


setup(name = 'ltradcapi',
	version='1.0',
	ext_modules=[Extension("_ltradcapi",
                             sources=["ltradcapi.i"],
                             include_dirs=["ltr"],
                             libraries = ['ltr11api','ltrapi', 'ltr210api'])],
    py_modules=['ltradcapi']
    )


