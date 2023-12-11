//
//  CastBufExecution.hpp
//  MNN
//
//  Created by MNN on 2023/08/11.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MNN_OPENCL_BUFFER_CLOSED
#ifndef CastBufExecution_hpp
#define CastBufExecution_hpp

#include "core/Execution.hpp"

#include <vector>
#include "MNN_generated.h"
#include "backend/opencl/core/OpenCLBackend.hpp"
#include "backend/opencl/core/OpenCLRunningUtils.hpp"

namespace MNN {
namespace OpenCL {

class CastBufExecution : public Execution {
public:
    CastBufExecution(const std::string &compute, Backend *backend);
    virtual ~CastBufExecution() = default;

    virtual ErrorCode onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
    virtual ErrorCode onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;

private:
    cl::Kernel mKernel;
    uint32_t mMaxWorkGroupSize;
    std::vector<uint32_t> mGlobalWorkSize = {1, 1, 1};
    std::vector<uint32_t> mLocalSize      = {1, 1, 1};
    std::set<std::string> mBuildOptions;
};

} // namespace OpenCL
} // namespace MNN
#endif /* CastBufExecution_hpp */
#endif/* MNN_OPENCL_BUFFER_CLOSED */
