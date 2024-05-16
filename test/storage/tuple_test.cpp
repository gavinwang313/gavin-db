#include "catalog/schema.hpp"
#include "storage/tuple.hpp"
#include "gtest/gtest.h"
TEST(StorageTest, TupleTest) {
  auto c1 = db::Column("user_id", db::TypeId::INTEGER);
  auto c2 = db::Column("user_name", db::TypeId::VARCHAR, 40);
  auto schema = db::Schema({c1, c2});
  auto v1 = db::Value(db::TypeId::INTEGER, 2);
  auto v2 = db::Value(db::TypeId::VARCHAR, "hi", 2, true);
  auto tuple = db::Tuple({v1, v2}, schema);
  ASSERT_EQ(tuple.ToString(schema), "(2, hi)");
}

TEST(StorageTest, TupleTest2) {
  auto c1 = db::Column("user_id", db::TypeId::INTEGER);
  auto c2 = db::Column("user_name", db::TypeId::VARCHAR, 3);
  auto schema = db::Schema({c1, c2});
  auto v1 = db::Value(db::TypeId::INTEGER, 2);
  auto v2 = db::Value(db::TypeId::VARCHAR, "hii4", 4, true);
  auto tuple = db::Tuple({v1, v2}, schema);
}