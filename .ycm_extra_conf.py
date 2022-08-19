def Settings( **kwargs ):
  return {
    'flags': [ '-x', 'c', '-Wall', '-Werror', '-Wextra', '-I', 'includes/glad', '-I', 'includes' ],
  }
