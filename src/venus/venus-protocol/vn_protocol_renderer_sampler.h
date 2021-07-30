/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_SAMPLER_H
#define VN_PROTOCOL_RENDERER_SAMPLER_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* struct VkSamplerReductionModeCreateInfo chain */

static inline void *
vn_decode_VkSamplerReductionModeCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSamplerReductionModeCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSamplerReductionModeCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSamplerReductionMode(dec, &val->reductionMode);
}

static inline void
vn_decode_VkSamplerReductionModeCreateInfo_temp(struct vn_cs_decoder *dec, VkSamplerReductionModeCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerReductionModeCreateInfo_pnext_temp(dec);
    vn_decode_VkSamplerReductionModeCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkSamplerReductionModeCreateInfo_handle_self(VkSamplerReductionModeCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->reductionMode */
}

static inline void
vn_replace_VkSamplerReductionModeCreateInfo_handle(VkSamplerReductionModeCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            vn_replace_VkSamplerReductionModeCreateInfo_handle_self((VkSamplerReductionModeCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSamplerCreateInfo chain */

static inline void *
vn_decode_VkSamplerCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSamplerYcbcrConversionInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(dec);
            vn_decode_VkSamplerYcbcrConversionInfo_self_temp(dec, (VkSamplerYcbcrConversionInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSamplerReductionModeCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(dec);
            vn_decode_VkSamplerReductionModeCreateInfo_self_temp(dec, (VkSamplerReductionModeCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSamplerCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSamplerCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkFilter(dec, &val->magFilter);
    vn_decode_VkFilter(dec, &val->minFilter);
    vn_decode_VkSamplerMipmapMode(dec, &val->mipmapMode);
    vn_decode_VkSamplerAddressMode(dec, &val->addressModeU);
    vn_decode_VkSamplerAddressMode(dec, &val->addressModeV);
    vn_decode_VkSamplerAddressMode(dec, &val->addressModeW);
    vn_decode_float(dec, &val->mipLodBias);
    vn_decode_VkBool32(dec, &val->anisotropyEnable);
    vn_decode_float(dec, &val->maxAnisotropy);
    vn_decode_VkBool32(dec, &val->compareEnable);
    vn_decode_VkCompareOp(dec, &val->compareOp);
    vn_decode_float(dec, &val->minLod);
    vn_decode_float(dec, &val->maxLod);
    vn_decode_VkBorderColor(dec, &val->borderColor);
    vn_decode_VkBool32(dec, &val->unnormalizedCoordinates);
}

static inline void
vn_decode_VkSamplerCreateInfo_temp(struct vn_cs_decoder *dec, VkSamplerCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(dec);
    vn_decode_VkSamplerCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkSamplerCreateInfo_handle_self(VkSamplerCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->magFilter */
    /* skip val->minFilter */
    /* skip val->mipmapMode */
    /* skip val->addressModeU */
    /* skip val->addressModeV */
    /* skip val->addressModeW */
    /* skip val->mipLodBias */
    /* skip val->anisotropyEnable */
    /* skip val->maxAnisotropy */
    /* skip val->compareEnable */
    /* skip val->compareOp */
    /* skip val->minLod */
    /* skip val->maxLod */
    /* skip val->borderColor */
    /* skip val->unnormalizedCoordinates */
}

static inline void
vn_replace_VkSamplerCreateInfo_handle(VkSamplerCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            vn_replace_VkSamplerCreateInfo_handle_self((VkSamplerCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            vn_replace_VkSamplerYcbcrConversionInfo_handle_self((VkSamplerYcbcrConversionInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            vn_replace_VkSamplerReductionModeCreateInfo_handle_self((VkSamplerReductionModeCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateSampler_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateSampler *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkSamplerCreateInfo_temp(dec, (VkSamplerCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSampler = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSampler));
        if (!args->pSampler) return;
        vn_decode_VkSampler(dec, args->pSampler);
    } else {
        args->pSampler = NULL;
    }
}

static inline void vn_replace_vkCreateSampler_args_handle(struct vn_command_vkCreateSampler *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkSamplerCreateInfo_handle((VkSamplerCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pSampler */
}

static inline void vn_encode_vkCreateSampler_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateSampler *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateSampler_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pSampler))
        vn_encode_VkSampler(enc, args->pSampler);
}

static inline void vn_decode_vkDestroySampler_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroySampler *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkSampler_lookup(dec, &args->sampler);
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroySampler_args_handle(struct vn_command_vkDestroySampler *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkSampler_handle(&args->sampler);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroySampler_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroySampler *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroySampler_EXT});

    /* skip args->device */
    /* skip args->sampler */
    /* skip args->pAllocator */
}

static inline void vn_dispatch_vkCreateSampler(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateSampler args;

    if (!ctx->dispatch_vkCreateSampler) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateSampler_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateSampler(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkCreateSampler returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateSampler_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroySampler(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroySampler args;

    if (!ctx->dispatch_vkDestroySampler) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroySampler_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroySampler(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroySampler_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_SAMPLER_H */
