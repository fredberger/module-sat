{
  'targets': [
    {
      'target_name': 'sat',
      'sources': [
        'src/binding.cc',
        'src/settings_linux.cc',
        'src/settings_win.cc'
      ],
      'conditions': [
        ['OS!="linux"', { 'sources/': [['exclude', '_linux\\.cc$']] }],
        ['OS!="win"', {
          'sources/': [['exclude', '_win\\.cc$']],
          'libraries': ["-lsat"]
        }],
      ]
    }
  ]
}
