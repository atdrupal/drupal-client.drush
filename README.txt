drupal-client.drush
===================

### Install
 
mkdir ~/.drush
git clone https://gist.github.com/11eae5489f319efdc58c.git ~/.drush/drush_client
 
### Usage
 
drush dget node/1
drush dpost admin/config/system/site-information '{"site_name": "Drupal"}'
