// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#include "SingletonLogger.h"

#include <iostream>
#include <stdexcept>

numbat::SingletonLogger* singleton_logger_instance;

numbat::SingletonLogger* numbat::SingletonLogger::GetInstance() {
  if (singleton_logger_instance == nullptr) {
    singleton_logger_instance = new SingletonLogger();
  }
  return singleton_logger_instance;
}

void numbat::SingletonLogger::AddMetadata(numbat::Metadata metadata, std::string data) {
  m_metadata.insert_or_assign(metadata, data);
}

std::optional<std::string> numbat::SingletonLogger::GetData(numbat::Metadata key) {
  try {
    return m_metadata.at(key);
  } catch (std::out_of_range const& cant_find_key) {
    std::cerr << cant_find_key.what() << std::endl;
    return std::nullopt;
  }
}
