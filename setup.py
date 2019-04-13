from distutils.core import setup, Extension

argon2d_hash_module = Extension('argon2m_hash',
                               sources = ['argon2m_module.c',
                                          'argon2m.c',
                                          'argon2d/argon2.c',
                                          'argon2d/core.c',
                                          'argon2d/encoding.c',
                                          'argon2d/opt.c',
                                          'argon2d/thread.c',
                                          'blake2/blake2b.c'],
                            include_dirs=['.', './argon2d', './blake2'])

setup (name = 'argon2m_hash',
       version = '1.0',
       ext_modules = [argon2m_hash_module])