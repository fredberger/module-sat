{
  "targets": [
    {
      "target_name": "sat",
      "sources": [
        "src/binding.cc",
        "src/settings.cc"
      ],
      "link_settings": {
        "libraries": ["-lsat"]
      }
    }
  ]
}
