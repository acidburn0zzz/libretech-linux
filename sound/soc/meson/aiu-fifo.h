/* SPDX-License-Identifier: (GPL-2.0 OR MIT) */
/*
 * Copyright (c) 2019 BayLibre, SAS.
 * Author: Jerome Brunet <jbrunet@baylibre.com>
 */

#ifndef _MESON_AIU_FIFO_H
#define _MESON_AIU_FIFO_H

struct snd_pcm_hardware;
struct snd_soc_component_driver;
struct snd_soc_dai_driver;
struct clk;
struct snd_pcm_ops;
struct snd_pcm_substream;
struct snd_soc_dai;
struct snd_pcm_hw_params;
struct platform_device;

struct aiu_fifo_hw {
	struct snd_pcm_hardware *pcm;
	unsigned int mem_offset;
	unsigned int fifo_block;
};

struct aiu_fifo_match_data {
	const struct snd_soc_component_driver *component_drv;
	const struct aiu_fifo_hw *hw;
	struct snd_soc_dai_driver *dai_drv;
};

struct aiu_fifo {
	const struct aiu_fifo_hw *hw;
	struct clk *pclk;
	int irq;
};

extern const struct snd_pcm_ops aiu_fifo_pcm_ops;

int aiu_fifo_trigger(struct snd_pcm_substream *substream, int cmd,
		     struct snd_soc_dai *dai);
int aiu_fifo_prepare(struct snd_pcm_substream *substream,
		     struct snd_soc_dai *dai);
int aiu_fifo_hw_params(struct snd_pcm_substream *substream,
		       struct snd_pcm_hw_params *params,
		       struct snd_soc_dai *dai);
int aiu_fifo_hw_free(struct snd_pcm_substream *substream,
		     struct snd_soc_dai *dai);
int aiu_fifo_startup(struct snd_pcm_substream *substream,
		     struct snd_soc_dai *dai);
void aiu_fifo_shutdown(struct snd_pcm_substream *substream,
		       struct snd_soc_dai *dai);
int aiu_fifo_pcm_new(struct snd_soc_pcm_runtime *rtd,
		     struct snd_soc_dai *dai);

int aiu_fifo_component_probe(struct snd_soc_component *component);
int aiu_fifo_probe(struct platform_device *pdev);

#endif /* _MESON_AIU_FIFO_H */
