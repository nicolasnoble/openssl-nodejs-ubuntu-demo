{
  'targets': [
    {
      'target_name': 'openssl_example',
      'sources': [
        'openssl-example.cc'
      ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")',
        '<(node_root_dir)/deps/openssl/openssl/include'
      ],
      "conditions" : [
        ["target_arch=='ia32'", {
          "include_dirs": [ "<(node_root_dir)/deps/openssl/config/piii" ]
        }],
        ["target_arch=='x64'", {
          "include_dirs": [ "<(node_root_dir)/deps/openssl/config/k8" ]
        }],
        ["target_arch=='arm'", {
          "include_dirs": [ "<(node_root_dir)/deps/openssl/config/arm" ]
        }]
      ]
    }
  ]
}
