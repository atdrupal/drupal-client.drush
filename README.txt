drupal-client.drush
===================

### Install
 
mkdir ~/.drush
git clone https://github.com/andytruong/drupal-client.drush.git ~/.drush/drush_client
 
### Usage

drush dget node/1 --uid=123
drush dpost admin/config/system/site-information '{"site_name": "Drupal"}'
