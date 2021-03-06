/*
 * Tencent is pleased to support the open source community by making wwsearch
 * available.
 *
 * Copyright (C) 2018-present Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

#include "and_weight.h"
#include "and_scorer.h"

namespace wwsearch {

Scorer* AndWeight::GetScorer(SearchContext* context) {
  AndScorer* scorer = new AndScorer(this);
  for (auto w : sub_weight_) {
    Scorer* s = w->GetScorer(context);
    if (nullptr == s) {
      // error happen
      delete scorer;
      return nullptr;
    }
    scorer->AddScorer(s);
  }
  return scorer;
}

BulkScorer* AndWeight::GetBulkScorer(SearchContext* context) {
  // not implementataion now
  assert(false);
  return nullptr;
}

}  // namespace wwsearch
