/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_DESCRIPTOR_SET_LAYOUT_H
#define VN_PROTOCOL_RENDERER_DESCRIPTOR_SET_LAYOUT_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* struct VkDescriptorSetLayoutBinding */

static inline void
vn_decode_VkDescriptorSetLayoutBinding_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutBinding *val)
{
    vn_decode_uint32_t(dec, &val->binding);
    vn_decode_VkDescriptorType(dec, &val->descriptorType);
    vn_decode_uint32_t(dec, &val->descriptorCount);
    vn_decode_VkFlags(dec, &val->stageFlags);
    if (vn_peek_array_size(dec)) {
        val->pImmutableSamplers = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pImmutableSamplers) * val->descriptorCount);
        if (!val->pImmutableSamplers) return;
        vn_decode_array_size(dec, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkSampler_lookup(dec, &((VkSampler *)val->pImmutableSamplers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pImmutableSamplers = NULL;
    }
}

static inline void
vn_replace_VkDescriptorSetLayoutBinding_handle(VkDescriptorSetLayoutBinding *val)
{
    /* skip val->binding */
    /* skip val->descriptorType */
    /* skip val->descriptorCount */
    /* skip val->stageFlags */
    if (val->pImmutableSamplers) {
       for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_replace_VkSampler_handle(&((VkSampler *)val->pImmutableSamplers)[i]);
    }
}

/* struct VkDescriptorSetLayoutBindingFlagsCreateInfo chain */

static inline void *
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->bindingCount);
    if (vn_peek_array_size(dec)) {
        val->pBindingFlags = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBindingFlags) * val->bindingCount);
        if (!val->pBindingFlags) return;
        vn_decode_array_size(dec, val->bindingCount);
        for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_decode_VkFlags(dec, &((VkDescriptorBindingFlags *)val->pBindingFlags)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pBindingFlags = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle_self(VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->bindingCount */
    /* skip val->pBindingFlags */
}

static inline void
vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle(VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle_self((VkDescriptorSetLayoutBindingFlagsCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorSetLayoutCreateInfo chain */

static inline void *
vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDescriptorSetLayoutBindingFlagsCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(dec);
            vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(dec, (VkDescriptorSetLayoutBindingFlagsCreateInfo *)pnext);
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
vn_decode_VkDescriptorSetLayoutCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->bindingCount);
    if (vn_peek_array_size(dec)) {
        val->pBindings = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBindings) * val->bindingCount);
        if (!val->pBindings) return;
        vn_decode_array_size(dec, val->bindingCount);
        for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_decode_VkDescriptorSetLayoutBinding_temp(dec, &((VkDescriptorSetLayoutBinding *)val->pBindings)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pBindings = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetLayoutCreateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorSetLayoutCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkDescriptorSetLayoutCreateInfo_handle_self(VkDescriptorSetLayoutCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->bindingCount */
    if (val->pBindings) {
       for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_replace_VkDescriptorSetLayoutBinding_handle(&((VkDescriptorSetLayoutBinding *)val->pBindings)[i]);
    }
}

static inline void
vn_replace_VkDescriptorSetLayoutCreateInfo_handle(VkDescriptorSetLayoutCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            vn_replace_VkDescriptorSetLayoutCreateInfo_handle_self((VkDescriptorSetLayoutCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle_self((VkDescriptorSetLayoutBindingFlagsCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorSetVariableDescriptorCountLayoutSupport chain */

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(struct vn_cs_encoder *enc, const VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->maxVariableDescriptorCount);
}

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport(struct vn_cs_encoder *enc, const VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT });
    vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext(enc, val->pNext);
    vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(enc, val);
}

static inline void *
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxVariableDescriptorCount */
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext_partial_temp(dec);
    vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(dec, val);
}

/* struct VkDescriptorSetLayoutSupport chain */

static inline void
vn_encode_VkDescriptorSetLayoutSupport_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkDescriptorSetLayoutSupport_pnext(enc, pnext->pNext);
            vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(enc, (const VkDescriptorSetVariableDescriptorCountLayoutSupport *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkDescriptorSetLayoutSupport_self(struct vn_cs_encoder *enc, const VkDescriptorSetLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->supported);
}

static inline void
vn_encode_VkDescriptorSetLayoutSupport(struct vn_cs_encoder *enc, const VkDescriptorSetLayoutSupport *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT });
    vn_encode_VkDescriptorSetLayoutSupport_pnext(enc, val->pNext);
    vn_encode_VkDescriptorSetLayoutSupport_self(enc, val);
}

static inline void *
vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDescriptorSetVariableDescriptorCountLayoutSupport));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(dec);
            vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(dec, (VkDescriptorSetVariableDescriptorCountLayoutSupport *)pnext);
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
vn_decode_VkDescriptorSetLayoutSupport_self_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->supported */
}

static inline void
vn_decode_VkDescriptorSetLayoutSupport_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutSupport *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(dec);
    vn_decode_VkDescriptorSetLayoutSupport_self_partial_temp(dec, val);
}

static inline void vn_decode_vkCreateDescriptorSetLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateDescriptorSetLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDescriptorSetLayoutCreateInfo_temp(dec, (VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSetLayout = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSetLayout));
        if (!args->pSetLayout) return;
        vn_decode_VkDescriptorSetLayout(dec, args->pSetLayout);
    } else {
        args->pSetLayout = NULL;
    }
}

static inline void vn_replace_vkCreateDescriptorSetLayout_args_handle(struct vn_command_vkCreateDescriptorSetLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkDescriptorSetLayoutCreateInfo_handle((VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pSetLayout */
}

static inline void vn_encode_vkCreateDescriptorSetLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateDescriptorSetLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateDescriptorSetLayout_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pSetLayout))
        vn_encode_VkDescriptorSetLayout(enc, args->pSetLayout);
}

static inline void vn_decode_vkDestroyDescriptorSetLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyDescriptorSetLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorSetLayout_lookup(dec, &args->descriptorSetLayout);
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyDescriptorSetLayout_args_handle(struct vn_command_vkDestroyDescriptorSetLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorSetLayout_handle(&args->descriptorSetLayout);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyDescriptorSetLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyDescriptorSetLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyDescriptorSetLayout_EXT});

    /* skip args->device */
    /* skip args->descriptorSetLayout */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetDescriptorSetLayoutSupport_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetDescriptorSetLayoutSupport *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDescriptorSetLayoutCreateInfo_temp(dec, (VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSupport = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSupport));
        if (!args->pSupport) return;
        vn_decode_VkDescriptorSetLayoutSupport_partial_temp(dec, args->pSupport);
    } else {
        args->pSupport = NULL;
    }
}

static inline void vn_replace_vkGetDescriptorSetLayoutSupport_args_handle(struct vn_command_vkGetDescriptorSetLayoutSupport *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkDescriptorSetLayoutCreateInfo_handle((VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    /* skip args->pSupport */
}

static inline void vn_encode_vkGetDescriptorSetLayoutSupport_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetDescriptorSetLayoutSupport *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetDescriptorSetLayoutSupport_EXT});

    /* skip args->device */
    /* skip args->pCreateInfo */
    if (vn_encode_simple_pointer(enc, args->pSupport))
        vn_encode_VkDescriptorSetLayoutSupport(enc, args->pSupport);
}

static inline void vn_dispatch_vkCreateDescriptorSetLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateDescriptorSetLayout args;

    if (!ctx->dispatch_vkCreateDescriptorSetLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateDescriptorSetLayout_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateDescriptorSetLayout(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkCreateDescriptorSetLayout returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateDescriptorSetLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyDescriptorSetLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyDescriptorSetLayout args;

    if (!ctx->dispatch_vkDestroyDescriptorSetLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyDescriptorSetLayout_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyDescriptorSetLayout(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyDescriptorSetLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetDescriptorSetLayoutSupport(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetDescriptorSetLayoutSupport args;

    if (!ctx->dispatch_vkGetDescriptorSetLayoutSupport) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetDescriptorSetLayoutSupport_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetDescriptorSetLayoutSupport(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetDescriptorSetLayoutSupport_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_DESCRIPTOR_SET_LAYOUT_H */
