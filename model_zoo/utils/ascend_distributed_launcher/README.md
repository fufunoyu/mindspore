# Run distribute pretrain

## description
The number of D chips can be automatically allocated based on the device_num set in hccl config file, You don not need to specify that.


## how to use
For example, if we want to run the distributed training of Bert model on D chip, we can in `/bert/` dir:
```
python model_zoo/utils/ascend_distributed_launcher/run_distributed.py --run_script_dir ./run_pretrain.py --hyper_parameter_config_dir model_zoo/utils/ascend_distributed_launcher/hyper_parameter_config.ini --data_dir /path/dataset/ --hccl_config_dir model_zoo/utils/hccl_tools/hccl_2p_56_x.x.x.x.json
```

output:

```
hccl_config_dir: model_zoo/utils/hccl_tools/hccl_2p_56_x.x.x.x.json
the number of logical core: 192
avg_core_per_rank: 96
rank_size: 2

start training for rank 0, device 5:
rank_id: 0
device_id: 5
core nums: 0-95
epoch_size: 8
data_dir: /data/small_512/
schema_dir:
log file dir: ./LOG5/log.txt

start training for rank 1, device 6:
rank_id: 1
device_id: 6
core nums: 96-191
epoch_size: 8
data_dir: /data/small_512/
schema_dir:
log file dir: ./LOG6/log.txt
```

## Note

1. Note that `hccl_2p_56_x.x.x.x.json` can use [hccl_tools.py](https://gitee.com/mindspore/mindspore/tree/master/model_zoo/utils/hccl_tools) to generate.

2. For hyper parameter, please note that you should customize the scripts `hyper_parameter_config.ini`. Please note that these two hyper parameters are not allowed to be configured here:
    device_id
    device_num

3. For Other Model, please note that you should customize the option `run_script` and Corresponding `hyper_parameter_config.ini`.