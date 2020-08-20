/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "src/ir/primitive_t_value.h"

namespace mindspore::lite {
std::shared_ptr<PrimitiveTValue> GetReturnPrim() {
  auto return_primitiveT = new schema::PrimitiveT;
  return_primitiveT->value.type = schema::PrimitiveType_Return;
  return_primitiveT->value.value = new schema::ReturnT;
  return std::make_shared<PrimitiveTValue>(return_primitiveT);
}

std::shared_ptr<PrimitiveTValue> GetMakeTuplePrim() {
  auto make_tuple_primitiveT = new schema::PrimitiveT;
  make_tuple_primitiveT->value.type = schema::PrimitiveType_MakeTuple;
  make_tuple_primitiveT->value.value = new schema::MakeTupleT;
  return std::make_shared<PrimitiveTValue>(make_tuple_primitiveT);
}

std::shared_ptr<PrimitiveTValue> GetTupleGetItemPrim() {
  auto tuple_get_item_primitiveT = new schema::PrimitiveT();
  tuple_get_item_primitiveT->value.type = schema::PrimitiveType_TupleGetItem;
  tuple_get_item_primitiveT->value.value = new schema::TupleGetItemT;
  return std::make_shared<PrimitiveTValue>(tuple_get_item_primitiveT);
}
}  // namespace mindspore::lite