// Copyright (c) 2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#include <optional>

#include "SingletonLogger.h"
#include "gtest/gtest.h"

TEST(SingletonLoggerTest, Creation) {
  numbat::SingletonLogger* logger1 = numbat::SingletonLogger::GetInstance();
  numbat::SingletonLogger* logger2 = numbat::SingletonLogger::GetInstance();
  ASSERT_EQ(logger1, logger2);
}

TEST(SingletonLoggerTest, Metadata) {
  numbat::SingletonLogger* logger = numbat::SingletonLogger::GetInstance();
  logger->AddMetadata(numbat::Metadata::Date, "28/02/2024");
  logger->AddMetadata(numbat::Metadata::ProjectName, "Numbat");
  ASSERT_EQ(logger->GetData(numbat::Metadata::Date), "28/02/2024");
  ASSERT_EQ(logger->GetData(numbat::Metadata::ProjectName), "Numbat");
  ASSERT_EQ(logger->GetData(numbat::Metadata::GitHash), std::nullopt);
}
