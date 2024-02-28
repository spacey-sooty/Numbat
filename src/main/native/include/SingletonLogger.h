// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#pragma once

#include <optional>
#include <string>
#include <unordered_map>

namespace numbat {

/* An item to track the metadata of your project. */
enum Metadata {
  /* The name of the project. */
  ProjectName,
  /* The git hash that the log was taken on. */
  GitHash,
  /* The git branch of the log was taken on. */
  GitBranch,
  /* The date the log was taken. */
  Date,
};

/* A global logger class to store things like project metadata or configuration data */
class SingletonLogger {
 public:
  /* Gets the instance of the logger */
  static SingletonLogger* GetInstance();

  /**
   * Adds or updates the stored metadata with the associated key and value.
   *
   * @param metadata The Metadata key that should be assigned to.
   * @param value The value to assign to the key, should be a string.
   */
  void AddMetadata(Metadata metadata, std::string value);

  /**
   * Gets the metadata value from the stored instance.
   *
   * @param key The key to fetch from.
   */
  std::optional<std::string> GetData(Metadata key);

 private:
  std::unordered_map<Metadata, std::string> m_metadata;
};

}  // namespace numbat
